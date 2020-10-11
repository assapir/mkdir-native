#ifndef SRC_MKDIR_H
#define SRC_MKDIR_H

#include <napi.h>
#include <string>
#include <system_error>

using namespace Napi;

class MkDirWorker : public AsyncWorker {
    
    public:
        MkDirWorker(Function& callback, const std::string& dir_to_add);
        virtual ~MkDirWorker() { };

        void Execute();
        void OnOK();

    private:
        const std::string path;
        std::error_code ec;
};

#endif // SRC_MKDIR_H