#pragma once

#include "ofxTween.h"

class ofxAnimationData
{
public:
    ofxAnimationData()
    {
        
    }
    
    virtual ~ofxAnimationData()
    {
        
    }
};

class ofxAnimation
{
public:
    ofxAnimation()
    {
        init();
        setup();
    }
    
    virtual ~ofxAnimation()
    {
        
    }
    
    void init()
    {
        setFramesInOut(30, 30);
        bPlaying = false;
        bEndImmediately = false;
        bAnimatingIn = false;
        bAnimatingOut = false;
        bAnimating = false;
    }
    
    void setAnimatingIn()
    {
        bAnimatingIn = true;
        bAnimating = false;
        bAnimatingOut = false;
    }
    
    void setAnimatingOut()
    {
        bAnimatingIn = false;
        bAnimating = false;
        bAnimatingOut = true;
    }
    
    void setAnimating()
    {
        bAnimatingIn = false;
        bAnimating = true;
        bAnimatingOut = false;
    }
    
    void updateState()
    {
        if(bPlaying && currentFrameIn <= framesIn)
        {
            setAnimatingIn();
            updatingIn();
            currentFrameIn++;
            if(bEndImmediately && currentFrameIn > framesIn)
            {
                stop(); 
            }
        }
        else if(bPlaying)
        {
            setAnimating();
            updating();
        }
        else if(!bPlaying && currentFrameOut <= framesOut)
        {
            setAnimatingOut();
            updatingOut();
            currentFrameOut++;
            if(currentFrameOut > framesOut)
            {
                bAnimatingIn = false;
                bAnimating = false;
                bAnimatingOut = false;
                end();
            }
        }
    }
    
    void update()
    {
        updateState();
    }
    
    void draw()
    {
        if(bAnimatingIn)
        {
            drawingIn();
        }
        else if(bAnimating)
        {
            drawing();
        }
        else if(bAnimatingOut)
        {
            drawingOut();
        }
    }
    
    double getPercentBackIn() { return easingBack.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentBackOut() { return easingBack.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentBackInOut() { return easingBack.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentBounceIn() { return easingBounce.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentBounceOut() { return easingBounce.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentBounceInOut() { return easingBounce.easeInOut(getPercent(), 0.0, 1.0, 1.0); }

    double getPercentCircIn() { return easingCirc.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentCircOut() { return easingCirc.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentCircInOut() { return easingCirc.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentCubicIn() { return easingCubic.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentCubicOut() { return easingCubic.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentCubicInOut() { return easingCubic.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentElasticIn() { return easingElastic.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentElasticOut() { return easingElastic.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentElasticInOut() { return easingElastic.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentExpoIn() { return easingExpo.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentExpoOut() { return easingExpo.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentExpoInOut() { return easingExpo.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentQuadIn() { return easingQuad.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuadOut() { return easingQuad.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuadInOut() { return easingQuad.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentQuartIn() { return easingQuart.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuartOut() { return easingQuart.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuartInOut() { return easingQuart.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentQuintIn() { return easingQuint.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuintOut() { return easingQuint.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentQuintInOut() { return easingQuint.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    double getPercentSineIn() { return easingSine.easeIn(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentSineOut() { return easingSine.easeOut(getPercent(), 0.0, 1.0, 1.0); }
    double getPercentSineInOut() { return easingSine.easeInOut(getPercent(), 0.0, 1.0, 1.0); }
    
    //
    
    double getPercentInverseBackIn() { return easingBack.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseBackOut() { return easingBack.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentvBackInOut() { return easingBack.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseBounceIn() { return easingBounce.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseBounceOut() { return easingBounce.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseBounceInOut() { return easingBounce.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseCircIn() { return easingCirc.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseCircOut() { return easingCirc.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseCircInOut() { return easingCirc.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseCubicIn() { return easingCubic.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseCubicOut() { return easingCubic.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseCubicInOut() { return easingCubic.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseElasticIn() { return easingElastic.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseElasticOut() { return easingElastic.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseElasticInOut() { return easingElastic.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseExpoIn() { return easingExpo.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseExpoOut() { return easingExpo.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseExpoInOut() { return easingExpo.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseQuadIn() { return easingQuad.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuadOut() { return easingQuad.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuadInOut() { return easingQuad.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseQuartIn() { return easingQuart.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuartOut() { return easingQuart.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuartInOut() { return easingQuart.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseQuintIn() { return easingQuint.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuintOut() { return easingQuint.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseQuintInOut() { return easingQuint.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    double getPercentInverseSineIn() { return easingSine.easeIn(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseSineOut() { return easingSine.easeOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    double getPercentInverseSineInOut() { return easingSine.easeInOut(getPercentInverse(), 0.0, 1.0, 1.0); }
    
    
    double getPercent()
    {
        if(bAnimatingIn)
        {
            return getPercentIn();
        }
        else if(bAnimatingOut)
        {
            return 1.0 - getPercentOut();
        }
        return 1.0;
   }
    
    double getPercentInverse()
    {
        if(bAnimatingIn)
        {
            return 1.0 - getPercentIn();
        }
        else if(bAnimatingOut)
        {
            return getPercentOut();
        }
        return 0.0;
    }
    
    double getPercentInInverse()
    {
        return 1.0 - getPercentIn();
    }
    
    double getPercentIn()
    {
        return currentFrameIn/framesIn;
    }
    
    double getPercentOutInverse()
    {
        return 1.0 - getPercentOut();
    }
    
    double getPercentOut()
    {
        return currentFrameOut/framesOut;
    }
    
    bool isPlaying()
    {
        return bPlaying;
    }
    
    void togglePlay()
    {
        if(isPlaying())
        {
            stop();
        }
        else
        {
            play();
        }
    }
    
    void play()
    {
        start();
        setPlaying(true);
        currentFrameIn = 0;
    }
    
    void setPlaying(bool _bPlaying)
    {
        bPlaying = _bPlaying;
    }
    
    void stop()
    {
        if(isPlaying())
        {
            setPlaying(false);
            currentFrameOut = 0;
        }
    }
    
    void setFramesInOut(int _framesIn, int _framesOut)
    {
        setFramesIn(_framesIn);
        setFramesOut(_framesOut);
    }
    
    void setFramesIn(int _framesIn)
    {
        framesIn = _framesIn;
        currentFrameIn = 0;
    }
    
    void setFramesOut(int _framesOut)
    {
        framesOut = _framesOut;
        currentFrameOut = framesOut+1;
    }
    
    virtual void setData(ofxAnimationData *_data)
    {
        data = _data;
    }
    
    void setEndImmediately(bool _bEndImmediately)
    {
        bEndImmediately = _bEndImmediately;
    }
    //SubClass & Override
    
    virtual string getName()
    {
        return "BASE";
    }
    
    virtual void setup()
    {
        
    }
    
    virtual void drawingIn()
    {
        drawing();
    }
    
    virtual void drawing()
    {
        
    }
    
    virtual void drawingOut()
    {
        drawing();
    }
    
    virtual void updatingIn()
    {
        updating();
    }
    
    virtual void updating()
    {
        
    }
    
    virtual void updatingOut()
    {
        updating();
    }
    
    virtual void start()
    {
        
    }
    
    virtual void end()
    {
        
    }
    
protected:
    ofxEasingBack easingBack;
    ofxEasingBounce easingBounce;
    ofxEasingCubic  easingCubic;
    ofxEasingElastic easingElastic;
    ofxEasingQuart easingQuart;
    ofxEasingCirc easingCirc;
    ofxEasingExpo easingExpo;
    ofxEasingQuad easingQuad;
    ofxEasingQuint easingQuint;
    ofxEasingSine easingSine;
    
    bool bEndImmediately;
    bool bAnimatingIn;
    bool bAnimatingOut;
    bool bAnimating;
    
    bool bPlaying;
    double framesIn;
    double framesOut;
    double currentFrameIn;
    double currentFrameOut;
    ofxAnimationData *data = NULL;
};

class ofxAnimationEngine
{
public:
    ofxAnimationEngine()
    {
        
    }
    
    ~ofxAnimationEngine()
    {
        vector<ofxAnimation *>::iterator it = animations.begin();
        vector<ofxAnimation *>::iterator eit = animations.end();
        for(; it != eit; ++it)
        {
            ofxAnimation *a = (*it);
            delete a;
        }
        animations.clear();
        animationMap.clear();
    }
    
    void update()
    {
        vector<ofxAnimation *>::iterator it = animations.begin();
        vector<ofxAnimation *>::iterator eit = animations.end();
        for(; it != eit; ++it)
        {
            (*it)->update();
        }
    }
    
    void draw()
    {
        vector<ofxAnimation *>::iterator it = animations.begin();
        vector<ofxAnimation *>::iterator eit = animations.end();
        for(; it != eit; ++it)
        {
            (*it)->draw();
        }
    }
    
    void addAnimation(ofxAnimation *a)
    {
        animationMap[a->getName()] = a;
        animations.push_back(a);
    }
    
    void play(string name)
    {
        ofxAnimation *a = animationMap[name];
        if(a != NULL)
        {
            a->play();
        }
    }
    
    void stop(string name)
    {
        ofxAnimation *a = animationMap[name];
        if(a != NULL)
        {
            a->stop();
        }
    }
    
    void toggle(string name)
    {
        ofxAnimation *a = animationMap[name];
        if(a != NULL)
        {
            a->togglePlay();
        }
    }
    
    int getCount()
    {
        return animations.size();
    }
    
    ofxAnimation *getAnimation(int index)
    {
        if(index < getCount())
        {
            return animations[index];
        }
        return NULL;
    }
    
    map<string, ofxAnimation *> animationMap;
    vector<ofxAnimation *> animations;
};