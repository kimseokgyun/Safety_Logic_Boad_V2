from intelhex import IntelHex  


def crc16(data, poly=0x1021, init=0xFFFF):
    crc = init
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ poly) if (crc & 0x8000) else (crc << 1)
            crc &= 0xFFFF
    return crc

import sys
hexfile = sys.argv[1]
ih = IntelHex(hexfile)

# 주소는 예시 (수정 필요)
start = 0x1D000000
end   = 0x1D01FEFF
crc_addr = 0x1D1FFF00

# CRC 계산
data = bytearray(ih[addr] for addr in range(start, end + 1))

crc = crc16(data)
print(f"Calculated CRC16: 0x{crc:04X}")
# CRC 삽입 (Big Endian)
ih[crc_addr] = (crc >> 8) & 0xFF
ih[crc_addr+1] = crc & 0xFF
ih[crc_addr+2] = 0
ih[crc_addr+3] = 0

# 저장 (덮어쓰기)
ih.write_hex_file(hexfile)
