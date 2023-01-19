# neovim-cc

We let Neovim run specific method through msgpack-rpc.

Msgpack is like Json, but smaller and faster.

RPC is remote procedure call, it's used to run specific method, which is running on server.

To implement rpc at client, we should be able to:

1. send request(including callid, parameters, etc) to neovim server, we can use socket.
2. get response from neovim server, we can also use socket.

And the interchange format is msgpack, so it is called msgpack-rpc.

## TODO

[✓] rewrite socket.h using asio.

[✓] rewrite logic of api generation.
