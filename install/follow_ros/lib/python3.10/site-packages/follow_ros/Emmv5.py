import serial

def send_speed_command(ser: serial.Serial, address: int, direction: int, speed_rpm: int) -> str:
    """
    发送速度控制命令

    参数：
        ser         - 串口对象（已打开）
        address     - 设备地址 (0x00 ~ 0xFF)
        direction   - 方向 (0x00 = CW, 0x01 = CCW)
        speed_rpm   - 速度 (单位 RPM，0~65535)
    
    硬编码：
        加速度档位 = 0x0A
        多机同步 = 0x00
    """
    # 拆分速度为高低位
    speed_high = (speed_rpm >> 8) & 0xFF
    speed_low = speed_rpm & 0xFF

    # 构造命令
    cmd = [
        address & 0xFF,
        0xF6,
        direction & 0x01,
        speed_high,
        speed_low,
        0x0A,   # 加速度档位（固定）
        0x00,    # 多机同步标志（固定）
        0x6B
    ]
    ser.write(bytes(cmd))
