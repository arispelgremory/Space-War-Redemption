#ifndef SPACEWARREDEMPTIONX_DIRECTINPUT_H
#define SPACEWARREDEMPTIONX_DIRECTINPUT_H
#include "GameConfiguration.h"

// make this more reusable???
class InputManager {
    public:
        InputManager();
        ~InputManager();

        static InputManager* GetInstance();
        // Initialize
        void Init(HWND g_hWnd);

        // Clean Up
        void CleanUpInput();

        // Reset all keys
        void ResetAllKeys();

        void GetInput();

        // Getters
        bool GetUpButtonPressed() const;
        bool GetDownButtonPressed() const;
        bool GetEnterButtonPressed() const;
        bool GetLeftButtonPressed() const;
        bool GetRightButtonPressed() const;
        bool GetLeftMouseClicked() const;
        bool GetBackSpaceButtonPressed() const;
        bool GetMouseMoved() const; //?
        bool GetWButtonPressed() const;
        bool GetAButtonPressed() const;
        bool GetSButtonPressed() const;
        bool GetDButtonPressed() const;

        // Reset Input (Setters)
        void ResetUpButton();
        void ResetDownButton();
        void ResetEnterButton();
        void ResetLeftButton();
        void ResetRightButton();
        void ResetLeftMouseButton();
        void ResetBackSpaceButton();
        void ResetWButton();
        void ResetAButton();
        void ResetSButton();
        void ResetDButton();



    private:
        static InputManager* _instance;
        // Direct Input
        LPDIRECTINPUT8 dInput;
        // Direct Input Keyboard Device
        LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
        // Direct Input Mouse Device
        LPDIRECTINPUTDEVICE8 dInputMouseDevice;

        //	Key input buffer
        BYTE  diKeys[256];

        // Mouse input buffer
        DIMOUSESTATE mouseState;

        // Player 1
        bool upButtonPressed;
        bool downButtonPressed;
        bool leftButtonPressed;
        bool rightButtonPressed;

        // Player 2
        bool wButtonPressed;
        bool aButtonPressed;
        bool sButtonPressed;
        bool dButtonPressed;

        bool enterButtonPressed;
        bool leftMouseClicked;
        bool backSpaceButtonPressed;


};


#endif //SPACEWARREDEMPTIONX_DIRECTINPUT_H
