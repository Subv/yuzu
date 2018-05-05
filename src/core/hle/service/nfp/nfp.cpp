// Copyright 2018 yuzu emulator team
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/logging/log.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/nfp/nfp.h"
#include "core/hle/service/nfp/nfp_user.h"

namespace Service::NFP {

Module::Interface::Interface(std::shared_ptr<Module> module, const char* name)
    : ServiceFramework(name), module(std::move(module)) {}

class IUser final : public ServiceFramework<IUser> {
public:
    IUser() : ServiceFramework("IUser") {
        static const FunctionInfo functions[] = {
            {0, &IUser::Initialize, "Initialize"}, {1, &IUser::Initialize, "Unknown1"},
            {2, &IUser::Initialize, "Unknown2"},   {3, &IUser::Initialize, "Unknown3"},
            {4, &IUser::Initialize, "Unknown4"},   {5, &IUser::Initialize, "Unknown5"},
            {6, &IUser::Initialize, "Unknown6"},   {7, &IUser::Initialize, "Unknown7"},
            {8, &IUser::Initialize, "Unknown8"},   {9, &IUser::Initialize, "Unknown9"},
            {10, &IUser::Initialize, "Unknown10"}, {11, &IUser::Initialize, "Unknown11"},
            {12, &IUser::Initialize, "Unknown12"}, {13, &IUser::Initialize, "Unknown13"},
            {14, &IUser::Initialize, "Unknown14"}, {15, &IUser::Initialize, "Unknown15"},
            {16, &IUser::Initialize, "Unknown16"}, {17, &IUser::Initialize, "Unknown17"},
            {18, &IUser::Initialize, "Unknown18"}, {19, &IUser::Initialize, "Unknown19"},
            {20, &IUser::Initialize, "Unknown20"}, {21, &IUser::Initialize, "Unknown21"},
            {22, &IUser::Initialize, "Unknown22"}, {23, &IUser::Initialize, "Unknown23"},
            {24, &IUser::Initialize, "Unknown24"},
        };
        RegisterHandlers(functions);
    }

private:
    void Initialize(Kernel::HLERequestContext& ctx) {
        NGLOG_WARNING(Service_NFP, "(STUBBED) called");
        IPC::ResponseBuilder rb{ctx, 2};
        rb.Push(RESULT_SUCCESS);
    }
};

void Module::Interface::CreateUserInterface(Kernel::HLERequestContext& ctx) {
    NGLOG_DEBUG(Service_NFP, "called");
    IPC::ResponseBuilder rb{ctx, 2, 0, 1};
    rb.Push(RESULT_SUCCESS);
    rb.PushIpcInterface<IUser>();
}

void InstallInterfaces(SM::ServiceManager& service_manager) {
    auto module = std::make_shared<Module>();
    std::make_shared<NFP_User>(module)->InstallAsService(service_manager);
}

} // namespace Service::NFP
