#ifndef RELAYCONTROLLER_H
#define RELAYCONTROLLER_H

class RelayController
{
  public:
    static const int Z_POSITION_NONE = 0;
    static const int Z_POSITION_DRY = 1;
    static const int Z_POSITION_WET = 2;
    static const int Z_POSITION_DMM = 3;
    static const int Z_POSITIONS_TOTAL = 4;

    static const int DRY_POSITION_BRANCHED = 0;
    static const int DRY_POSITION_LINEAR = 1;
    static const int DRY_POSITIONS_TOTAL = 2;

    static const int POLARITY_OPTION_NORMAL = 0;
    static const int POLARITY_OPTION_INVERTED = 1;
    static const int POLARITY_OPTIONS_TOTAL = 2;

  	RelayController(int pinDryAfter, int pinDryZ, int pinWetZ, int pinDmmZ, int pinPolarityFlip):
      pinDryAfter(pinDryAfter),
      pinDryZ(pinDryZ),
      pinWetZ(pinWetZ),
      pinDmmZ(pinDmmZ),
      pinPolarityFlip(pinPolarityFlip) {}

    void setup();

    void setZPosition(int newZPosition);
    void setDryPosition(int newDryPosition);
    void setPolarityOption(int newPolarityOption);

  private:
  	int pinDryAfter;
    int pinDryZ;
    int pinWetZ;
    int pinDmmZ;
    int pinPolarityFlip;
};

#endif
