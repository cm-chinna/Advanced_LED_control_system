//hello valueVertex solutions i created code for LED control system in 4 LED's i hope you find good in this assignment :)
#include <stdio.h> //standard libraries for i/o functions
#include <stdint.h> //integer types of uint8_t and uint32_t

#define NUM_LEDS 4 //4LED are grouped

typedef struct
{
    uint8_t state; //LED state like ON/OFF 8-bit integer
    uint8_t brightness; //LED brightness level stored in 8-bit integer
    uint32_t color; //LED color for RGB and Alpha in 32-bit integer
}
LEDSettings; //state,brightness and color are stored in here

typedef struct {
    LEDSettings singleLED[NUM_LEDS]; //array of LEDSettings staored settings for muiltiple LED's (4)
    uint8_t groupState; //all LED group ON/OFF state
    uint8_t groupBrightness; //all LED group brightness level
}
LEDGroup; //group of state and brightness are stored in here

void initLEDGroup(LEDGroup *group)
{
    group->groupState = 0; //initially OFF condition
    group->groupBrightness = 0; //initially OFF  minimum brightness condition
    for (int i = 0; i < NUM_LEDS; i++)
    {
        group->singleLED[i].state = 0; //looping the LED's state as OFF
        group->singleLED[i].brightness = 0; //looping the LED's brightness as OFF
        group->singleLED[i].color = 0x000000; //looping the LED's color as OFF
    }
}

void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color) 
{
    group->groupState = groupState; //in here the vakue of each LED's are changed
    group->groupBrightness = groupBrightness; //in here the value of each LED's are changed
    for (int i = 0; i < NUM_LEDS; i++)
    {
        group->singleLED[i].state = state; // update state value
        group->singleLED[i].brightness = brightness; // update brightness value
        group->singleLED[i].color = color; //  update color value
    }
}

void displayLEDGroupStatus(const LEDGroup *group)
{
    printf("Group State: %d\n", group->groupState); //here printing the group state
    printf("Group Brightness: %d\n", group->groupBrightness); //here printing the group brightness
    for (int i = 0; i < NUM_LEDS; i++) {
        printf("LED %d State: %d, Brightness: %d, Color: %#x\n", i, group->singleLED[i].state, group->singleLED[i].brightness, group->singleLED[i].color); //printing the state , brighness , color of each LED's color as in hexadecimal
    }
}

int main()
{
    LEDGroup group; //store LEDgroup  to LED setting
    initLEDGroup(&group); //initialize a default values
    printf("Initial LED Group Status:\n"); //printing header for initial stage
    displayLEDGroupStatus(&group); //displaying initial status
    updateLEDGroupSettings(&group, 1, 150, 1, 100, 0xFF0000); //grouping updated status
    printf("\nUpdated LED Group Status:\n"); //displaying updated status
    displayLEDGroupStatus(&group);

    return 0;
}
