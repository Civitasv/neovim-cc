#!/usr/bin/python
# -*- coding: utf-8 -*-

from jinja2 import Environment, FileSystemLoader
import msgpack
import os
import subprocess
import re


def api_info():
    nvim_api_info = subprocess.check_output(["nvim", "--api-info"])
    unpacked_api = msgpack.unpackb(nvim_api_info)

    return unpacked_api


class InvalidType(Exception):
    pass


class NativeType:
    def __init__(self, name, expect_ref=False):
        self.name = name
        self.expect_ref = expect_ref


TYPE_DICT = {
    "void": NativeType("void"),
    "Integer": NativeType("int64_t"),
    "Float": NativeType("double"),
    "Boolean": NativeType("bool"),
    "String": NativeType("std::string", True),
    "Object": NativeType("Variant", True),
    "Array": NativeType("std::vector<Variant>", True),
    "Dictionary": NativeType("std::map<std::string, Variant>", True),
    "Window": NativeType("Window"),
    "Buffer": NativeType("Buffer"),
    "Tabpage": NativeType("Tabpage"),
    "ArrayOf(Integer, 2)": NativeType("std::pair<int64_t, int64_t>", True),
}

ARRAY_OF = re.compile(r"ArrayOf\(\s*(\w+)\s*\)")


def convert_type_to_native(nvim_t, enable_ref_op):
    obj = ARRAY_OF.match(nvim_t)
    if obj:
        ret = "std::vector<%s>" % convert_type_to_native(obj.groups()[0], False)
        return "const " + ret + "&" if enable_ref_op else ret

    if nvim_t in TYPE_DICT:
        native_t = TYPE_DICT[nvim_t]
        return (
            "const " + native_t.name + "&"
            if enable_ref_op and native_t.expect_ref
            else native_t.name
        )
    else:
        print("unknown nvim type name: " + str(nvim_t))
        raise InvalidType()


def main():
    env = Environment(loader=FileSystemLoader("templates", encoding="utf8"))
    tpl = env.get_template("nvim.h")

    api = api_info()

    functions = []
    for f in api["functions"]:
        d = {}
        d["name"] = f["name"]

        try:
            d["return"] = convert_type_to_native(f["return_type"], False)
            d["args"] = [
                {"type": convert_type_to_native(arg[0], True), "name": arg[1]}
                for arg in f["parameters"]
            ]
            functions.append(d)
        except InvalidType:
            print("invalid function = " + str(f))

    api = tpl.render({"functions": functions})

    with open(os.path.join("../include", "nvim.h"), "w") as f:
        f.write(api)


if __name__ == "__main__":
    main()
