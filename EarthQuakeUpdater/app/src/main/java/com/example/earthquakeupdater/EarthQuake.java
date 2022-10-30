package com.example.earthquakeupdater;

// An EarthQuake object contains information about a single  earthquake.

public class EarthQuake extends  Disaster{

    private double mMagnitude;



    //constructor to create a earthquake object
    public EarthQuake(double magnitude, String location, long timeInMilliseconds, String mUrl) {
        mMagnitude = magnitude;
        super.location = location;
        super.milliSeconds = timeInMilliseconds;
        super.mUrl = mUrl;
    }

    public double getMagnitude() {
        return mMagnitude;
    }
}