# -*- coding: utf-8 -*-

import torch
from torchvision.models.detection.faster_rcnn import fasterrcnn_resnet50_fpn
import numpy as np

def test():
    device = torch.device("cpu")
    array = np.random.randint(50,75,(2,2), dtype='int64')
    for _ in range(5):
        print(torch.as_tensor(array).float().to(device))
