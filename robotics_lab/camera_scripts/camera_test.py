import cv2
import pyrealsense2
from realsense_depth import DepthCamera
from ultralytics import YOLO
from ultralytics.utils.plotting import Annotator, colors

model = YOLO('yolov8m.pt')
names = model.names

dc = DepthCamera()

while True:
    ret, depth_frame, color_frame = dc.get_frame()
    if not ret:
        break

    results = model.track(color_frame, show=False, persist=True)
    annotator = Annotator(color_frame, line_width=2, example=model.names)

    for box in results[0].boxes:
        if box.is_track:
            x1, y1, x2, y2, id, confidence, box_class = box.data.squeeze().cpu().tolist()
            x1, y1, x2, y2 = map(int, [x1, y1, x2, y2])
            center_x = (x1 + x2) // 2
            center_y = (y1 + y2) // 2

            distance = depth_frame[center_y, center_x]
            color = colors(int(box_class), True)

            cv2.circle(color_frame, center=(center_x, center_y), radius=2, color=color, thickness=-1)
            cv2.putText(color_frame, text=f"Distance: {distance}cm", org=(center_x, center_y + 20), fontFace=cv2.FONT_HERSHEY_SIMPLEX, fontScale=.5, color=color, thickness=2)
            

            annotator.box_label(box.xyxy.squeeze().cpu().tolist(), color=colors(
                int(box_class), True), label=names[int(box_class)])

    cv2.imshow("Color Frame", color_frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

dc.release()
