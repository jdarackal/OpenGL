// XBoxController.cpp : Defines the entry point for the console application.
//

#include "XBoxController.h"
#include "XInputWrapper.h"
#include <iostream>
#include <math.h>

DWORD GamePad::XBoxController::GetControllerId()
{
    return id; // returning ID used in constructor
}

bool GamePad::XBoxController::IsConnected()
{
    if (xinput->XInputGetState(GetControllerId(), &State) == ERROR_SUCCESS) { // checking whether controller is connected
        return true;
    }
    
    return false;
}

bool GamePad::XBoxController::PressedA()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
        return true;
    }
    
    return false;
}

bool GamePad::XBoxController::PressedB()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_B) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedX()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_X) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedY()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_Y) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedLeftShoulder()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_LEFT_SHOULDER) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedRightShoulder()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_RIGHT_SHOULDER) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedLeftDpad()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_DPAD_LEFT) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedRightDpad()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_DPAD_RIGHT) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedUpDpad()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_DPAD_UP) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedDownDpad()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_DPAD_DOWN) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedStart()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_START) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedBack()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_BACK) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedLeftThumb()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_LEFT_THUMB) {
        return true;
    }

    return false;
}

bool GamePad::XBoxController::PressedRightThumb()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (State.Gamepad.wButtons == XINPUT_GAMEPAD_RIGHT_THUMB) {
        return true;
    }

    return false;
}

BYTE GamePad::XBoxController::LeftTriggerLocation()
{
    xinput->XInputGetState(GetControllerId(), &State);

    return State.Gamepad.bLeftTrigger;
}

BYTE GamePad::XBoxController::RightTriggerLocation()
{
    xinput->XInputGetState(GetControllerId(), &State);

    return State.Gamepad.bRightTrigger;
}

GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (abs(State.Gamepad.sThumbLX) <= radius) {
        State.Gamepad.sThumbLX = 0;
    } else if (State.Gamepad.sThumbLX < 0 && State.Gamepad.sThumbLX > -32768) {
        State.Gamepad.sThumbLX = (State.Gamepad.sThumbLX + radius) * scale;
    } else if (State.Gamepad.sThumbLX > 0 && State.Gamepad.sThumbLX < 32767) {
        State.Gamepad.sThumbLX = (State.Gamepad.sThumbLX - radius) * scale;
    }

    if (abs(State.Gamepad.sThumbLY) <= radius) {
        State.Gamepad.sThumbLY = 0;
    } else if (State.Gamepad.sThumbLY < 0 && State.Gamepad.sThumbLY > -32768) {
        State.Gamepad.sThumbLY = (State.Gamepad.sThumbLY + radius) * scale;
    } else if (State.Gamepad.sThumbLY > 0 && State.Gamepad.sThumbLY < 32767) {
        State.Gamepad.sThumbLY = (State.Gamepad.sThumbLY - radius) * scale;
    }

    return GamePad::Coordinate(XBoxController::State.Gamepad.sThumbLX, XBoxController::State.Gamepad.sThumbLY);
}

GamePad::Coordinate GamePad::XBoxController::RightThumbLocation()
{
    xinput->XInputGetState(GetControllerId(), &State);

    if (abs(State.Gamepad.sThumbRX) <= radius) {
        State.Gamepad.sThumbRX = 0;
    } else if (State.Gamepad.sThumbRX < 0 && State.Gamepad.sThumbRX > -32768) {
        State.Gamepad.sThumbRX = (State.Gamepad.sThumbRX + radius) * scale;
    } else if (State.Gamepad.sThumbRX > 0 && State.Gamepad.sThumbRX < 32767) {
        State.Gamepad.sThumbRX = (State.Gamepad.sThumbRX - radius) * scale;
    }
    
    if (abs(State.Gamepad.sThumbRY) <= radius) {
        State.Gamepad.sThumbRY = 0;
    } else if (State.Gamepad.sThumbRY < 0 && State.Gamepad.sThumbRY > -32768) {
        State.Gamepad.sThumbRY = (State.Gamepad.sThumbRY + radius) * scale;
    } else if (State.Gamepad.sThumbRY > 0 && State.Gamepad.sThumbRY < 32767) {
        State.Gamepad.sThumbRY = (State.Gamepad.sThumbRY - radius) * scale;
    }

    return GamePad::Coordinate(XBoxController::State.Gamepad.sThumbRX, XBoxController::State.Gamepad.sThumbRY);
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right)
{
    _XINPUT_VIBRATION Vibration;

    Vibration.wLeftMotorSpeed = left;
    Vibration.wRightMotorSpeed = right;

    xinput->XInputSetState(id, &Vibration);
}

void GamePad::XBoxController::SetDeadzone(unsigned int radius)
{
    this->radius = radius;
    scale = 32767.0 / (32767 - radius);
}
