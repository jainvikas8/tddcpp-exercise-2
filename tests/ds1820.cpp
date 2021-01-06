#include "ds1820.h"

namespace Sensor
{
    ROM_t Ds1820::read_rom()
    {
        ROM_t data = {{ 0x28, { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 }, 0x00 }}; //! OCLINT
        return data;
    }

    uint8_t Ds1820::calculate_CRC([[maybe_unused]] const uint8_t* data,
                                    [[maybe_unused]] uint32_t       num_of_bytes)
    {
        return 0;
    }

    void Ds1820::do_conversion() {}

    bool Ds1820::read_scratchpad(scratchpad_data_t* const data)
    {
        // default values
        // data->lsb = 0x50;
        // data->msb = 0x05;
        // data->crc = 0;
        return true;
    }

    float Ds1820::convert(uint16_t digital)
    {
        digital &= static_cast<uint16_t>(mask);
        int16_t s_digital = digital;
        return s_digital / 16.0f;
    }

};