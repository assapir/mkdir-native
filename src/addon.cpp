#include "mkdir.h"

Value runMkDirWorker(const CallbackInfo& info) {
    auto path = info[0].As<String>();
    Function callback = info[1].As<Function>();
    MkDirWorker* asyncWorker = new MkDirWorker(callback, path);
    asyncWorker->Queue();
    return info.Env().Undefined();
};

Object Init(Env env, Object exports) {
    exports["mkDirAsync"] = Function::New(env, runMkDirWorker, std::string("runMkDirWorker"));
    return exports;
}

NODE_API_MODULE(addon, Init)