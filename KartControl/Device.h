#pragma once
namespace kart {
    class Device {

        Device();

        ~Device();

        int getStatus();

        void preInit();

        void postInit();

        char *getName();

        bool isEnabled();

        void handleTick();
    };
}
