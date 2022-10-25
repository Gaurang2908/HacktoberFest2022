import tensorflow as tf
import tensorflow.keras.layers as layers
import tensorflow.keras.models as models
from tensorflow.keras.optimizers import Adam

import cv2
import pandas as pd
import numpy as np
import os 

import warnings
warnings.filterwarnings("ignore")

def convblock(model, filter):
    model = layers.Conv2D(filter, 3)(model)
    model = layers.Conv2D(filter, 3)(model)
    model = layers.ReLU()(model)
    model = layers.MaxPool2D()(model)
    return model

def upsampling(model, convblock, filters, x, even):
    if even:
        convblock = layers.Cropping2D(cropping=((x,x),(x,x)))(convblock)
    else:
        convblock = layers.Cropping2D(cropping=((x+1,x),(x+1,x)))(convblock)
    model = layers.Concatenate()([model, convblock])
    model = layers.Conv2D(filters, 3)(model)
    model = layers.Conv2D(filters, 3)(model)
    model = layers.ReLU()(model)
    model = layers.UpSampling2D()(model)

    return model
    
    def U_Net(input_shape):
    inp = layers.Input(input_shape)
    conv1 = convblock(inp, 8)
    conv2 = convblock(conv1, 16)
    conv3 = convblock(conv2, 32)
    conv4 = convblock(conv3, 64)
    # conv5 = convblock(conv4, 128)
    # conv6 = convblock(conv5, 256)
    conv7 = layers.Conv2D(512, 3)(conv4)
    conv8 = layers.Conv2D(512, 3)(conv7)
    # up1 = upsampling(conv8, conv6, 256)
    # up2 = upsampling(up1, conv5, 128)
    up3 = upsampling(conv8, conv4, 64, 2, True)
    up4 = upsampling(up3, conv3, 32, 10, True)
    up5 = upsampling(up4, conv2, 16, 26, False)
    up6 = upsampling(up5, conv1, 8,  59, True)
    end = layers.Conv2D(1, 3)(up6)

    model = models.Model(inputs=inp, outputs=end, name="U-Net")
    return model


model = U_Net((1024, 1024, 3))
model.summary()
