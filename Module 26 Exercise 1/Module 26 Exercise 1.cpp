// Module 26 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    string mood;
    const string Mood = u8"\U0001F642";
    const string Happy = u8"\U0001F60A";
    const string Left = u8"\U0001FAF2";
    const string Sad = u8"\U0001F614";
    const string Right = u8"\U0001FAF1";
    const string Angry = u8"\U0001F620";
    const string Excited = u8"\U0001F973"; 
    const string Emotion = u8"\U0001F601";

    cout << "Welcome to the Mood Emoji Responder! " << Mood << endl;
    cout << "How are you feeling today? (e.g., happy, sad, angry, excited): ";
    cin >> mood;

    // Normalize input to lowercase
    transform(mood.begin(), mood.end(), mood.begin(), ::tolower);

    cout << "Your mood: " << mood << endl;

    if (mood == "happy") {
        cout << "I am glad to hear that!" << Happy << endl; 
    }
    else if (mood == "sad") {
        cout << "Oh no! Here's a hug for you, it is ok." << Left <<""<< Sad <<""<< Right << endl;
    }
    else if (mood == "angry") {
        cout << "Take a deep breath." << Angry << endl;
    }
    else if (mood == "excited") {
        cout << "Woohoo! Let's celebrate!" << Excited << endl;
    }
    else {
        cout << "Hmm, I am not sure about that mood, but here is a smile anyway!" << Emotion << endl;
    }

    return 0;
}
