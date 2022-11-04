#pragma once
namespace kart {
    class Device {

        enum Status {
            SHUTDOWN = -3, ERR = -2, OK = -1

            // subclasses can add custom statuses by declaring their own enums
            // as long as the enums start at 0, they won't conflict with device enums
            // and 0 is the default so just don't modify
        };

        enum Error {
            NONE = -2, UNKNOWN = -1
        };

        Device();

        ~Device();

        virtual int getStatus() = 0;

        virtual int getError() = 0;

        virtual void init() = 0;

        virtual void preInit() = 0;

        virtual char *getName() = 0;

        virtual bool isEnabled() = 0;

        virtual void update() = 0;

        virtual void shutdown() = 0;
    };
}
