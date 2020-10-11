#include "mkdir.h"
#include <filesystem>
#include <system_error>

namespace fs = std::filesystem;

MkDirWorker::MkDirWorker(Function& callback, const std::string& path)
    : AsyncWorker(callback), path(path) {};

void MkDirWorker::Execute() {
    auto success = fs::create_directories(path, ec);
    if (!success) {
        const auto msg = "I wasn\'t able to do that, because: " + ec.message();
        SetError(msg);
    }
};

void MkDirWorker::OnOK() {
    std::string msg = "ok! we are good to go with " + path + " " + ec.message();
    Callback().Call({Env().Undefined(), String::New(Env(), msg)});
};