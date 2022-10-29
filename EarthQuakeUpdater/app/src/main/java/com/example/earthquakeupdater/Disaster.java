package com.example.earthquakeupdater;

public class Disaster {
    protected long milliSeconds;
    protected String location;
    protected long impacted;
    protected String mUrl;

    public long getImpacted(){
        return impacted;
    }
    public String getLocation() {
        return location;
    }

    public long getTimeInMilliseconds() {
        return milliSeconds;
    }

    public String getUrl() {
        return mUrl;
    }
}
