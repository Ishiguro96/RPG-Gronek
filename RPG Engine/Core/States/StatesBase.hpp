#pragma once

namespace eng{
    class StatesBase{
    public:
        virtual void Clear() = 0;
        virtual void HandleEvent() = 0;
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    };
}
