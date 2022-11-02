#pragma once
namespace kart {
    class Device {

        Device();

        ~Device();

        virtual int getStatus() = 0;

        virtual void preInit() = 0;

        virtual void postInit() = 0;

        virtual char *getName() = 0;

        virtual bool isEnabled() = 0;

        virtual void handleTick() = 0;
    };
}
