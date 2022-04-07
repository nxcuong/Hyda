# Hyda
hyda controller

GIỚI THIỆU

Hyda0810 là bo mạch đầu tiên thuộc dòng hyda, dựa trên vi xử lý mega 2560 của microchip.
VXL đã được nạp bootloader của arduino mega2560, do đó lập trình hoàn toàn tương tự.

Tổng quan bo mạch:
    Nguồn cấp: 24VDC
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
    
    
      
