# Hyda
hyda controller

GIỚI THIỆU

Hyda0810 là bo mạch đầu tiên thuộc dòng hyda, dựa trên vi xử lý mega 2560 của microchip.
VXL đã được nạp bootloader của arduino mega2560, do đó lập trình hoàn toàn tương tự.

Thiết kế: Được thiết kế để điều khiển các van điện từ thủy lực (hydraulic solenoid valves) trực tiếp mà không cần sử dụng rơ le trung gian.

Tổng quan bo mạch:

    Nguồn cấp điêu khiển 1A: 24VDC
    
    Nguồn cấp tải làm việc: Max 30A có bảo vệ ngược cực, tích hợp công tắc tổng (Main switch)
    
    Kênh DI: số lượng 08 kênh 24V DC
    
    Kênh DO: số lượng 08 kênh 24VDC
    
      - cấu hình ON/OFF đóng tải lên tới 5A
      
      - Cấu hình PWM, max 250Hz có thể điều khiển van tỷ lệ thủy lực
      
      - Hoàn toàn bảo vệ: ngắn mạch, chạm nguồn cấp, chuẩn đoán hở mạch, ngắn mạch, chập sang nguồn 24V
    Kênh i-DO: Số lượng 02
    
      - Cấu hình ON/OFF
      
      - Cấu hình PWM tần số lên tới 10kHz điều khiển van tỷ lệ
      
      - Mạch đo dòng hồi tiếp ra tải cho phép điều khiển vòng lặp dòng điện
      
    Cổng truyền thông: 01 CAN bus có thể dùng CAN0pen hoặc J1939
    
    Cổng mở rộng: 01 cổng mở rộng truyền thông SPI cho phép kết nối với 2 module mở rộng DI, DO, AI, CAN...
    
    Cổng UART: 01 cổng kết nối RS485 hoặc RS232
    
    
 LẬP TRÌNH
 
 Bước 1. Cài đặt phần mềm Arduino IDE: https://www.arduino.cc/en/software
 
 Bước 2. Mở chương trình arduino ide, trong phần File/preference copy và paste đường dẫn sau vào phần Additional boards manager URLs
 
 https://raw.githubusercontent.com/nxcuong/Hyda/main/package_hydra_index.json
 Nhấn OK để hoàn tất.
 
 Bước 3. Vào Tools/Board manager kéo thanh trượt xuống phía dưới tìm tới Hyda Family, sau đó chọn Install. nhấn closed sau khi cài đặt xong.
 
 Bước 4. Chọn mạch lập trình:
 
 Tools/Board/Hyda boards/Hyda
 
 Tools/Hyda board/Hyda0810
 
 Quá trình thêm bo mạch hoàn tất.

      
