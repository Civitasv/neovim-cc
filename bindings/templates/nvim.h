// Auto generated

#ifndef NEOVIM_CC__NVIM_H_
#define NEOVIM_CC__NVIM_H_

#include "nvim_rpc.h"
#include "type.h"
namespace nvim {

class Nvim {
public:
    void connect(const std::string &host, 
            const std::string &service, double timeout_sec = 1.0) {
        
        client_.connect(host, service, timeout_sec);
    }

{% for func in functions%}
    {{func.return}} {{func.name}} ({% for arg in func.args %}{{arg.type}} {{arg.name}}{% if not loop.last %}, {% endif %}{% endfor %}) { 
        {% if func.return != "void" %}
        {{func.return}} res;
        client_.call("{{func.name}}", res{% for arg in func.args %}, {{arg.name}}{% endfor %}); 
        return res;
        {% else %}
        client_.call("{{func.name}}", nullptr{% for arg in func.args %}, {{arg.name}}{% endfor %}); 
        {% endif %}
    }
{% endfor %}

private:
    NvimRPC client_;
};

} //namespace nvim

#endif //NEOVIM_CPP__NVIM_HPP_
