#pragma once
#include <Windows.h>

class FrameTimer
{
public:
    static FrameTimer* GetInstance();
    void Init(int);
    int framesToUpdate();
    // int GetFPS();
private:
    static FrameTimer* _instance;
    LARGE_INTEGER timerFreq;
    LARGE_INTEGER timeNow;
    LARGE_INTEGER timePrevious;
    int requestedFPS;
    float intervalsPerFrame;
    float intervalsSinceLastUpdate;
};
