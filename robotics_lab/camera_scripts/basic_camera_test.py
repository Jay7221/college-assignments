import cv2
from realsense_depth import DepthCamera
import numpy as np

dc = DepthCamera()

while True:
    ret, depth_frame, color_frame = dc.get_frame()
    if not ret:
        break
    cv2.imshow("Color Frame", color_frame)

    image_bw_uint8 = cv2.convertScaleAbs(depth_frame)
    colormap_image = cv2.applyColorMap(image_bw_uint8, cv2.COLORMAP_JET)
    cv2.imshow("Depth Frame", colormap_image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

dc.release()
