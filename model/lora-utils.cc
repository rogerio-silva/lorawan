/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Author: Romagnolo Stefano <romagnolostefano93@gmail.com>
 */

#include "lora-utils.h"
#include <cmath>

namespace ns3 {
namespace lorawan {

double
DbToRatio (double dB)
{
  double ratio = std::pow (10.0, dB / 10.0);
  return ratio;
}

double
DbmToW (double dBm)
{
  double mW = std::pow (10.0, dBm / 10.0);
  return mW / 1000.0;
}

double
WToDbm (double w)
{
  return 10.0 * std::log10 (w * 1000.0);
}

double
RatioToDb (double ratio)
{
  return 10.0 * std::log10 (ratio);
}

uint8_t SFToDR (uint8_t sf)
{
  // UE - 863-870 kHz table
  // DR 0 to 5 - SF 12 to 7 - 125 kHz
  // DR 6 - SF 7 - 250 kHz
  // This LoRaWAN module only implements 125 kHz.
  return (12 - sf);
}

uint8_t DRToSF (uint8_t dr)
{
  // UE - 863-870 kHz table
  // DR 0 to 5 - SF 12 to 7 - 125 kHz
  // DR 6 - SF 7 - 250 kHz
  // This LoRaWAN module only implements 125 kHz.

  std::vector<uint8_t> sf = { 12, 11, 10, 9, 8, 7, 7 };
  return sf.at (unsigned(dr));
}

}
} //namespace ns3
