/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libp2p/multi/converters/udp_converter.hpp>

#include <libp2p/common/byteutil.hpp>
#include <libp2p/multi/converters/conversion_error.hpp>

namespace libp2p::multi::converters {
  outcome::result<Bytes> UdpConverter::addressToBytes(std::string_view addr) {
    for (auto c : addr) {
      if (std::isdigit(c) == 0) {
        return ConversionError::INVALID_ADDRESS;
      }
    }
    int64_t port_int = 0;
    try {
      port_int = std::stoi(std::string(addr));
    } catch (std::exception &e) {
      return ConversionError::INVALID_ADDRESS;
    }
    if (port_int >= 0 and port_int <= 65535) {
      auto port_int16 = static_cast<uint16_t>(port_int);
      Bytes bytes;
      common::putUint16BE(bytes, port_int16);
      return std::move(bytes);
    }
    return ConversionError::INVALID_ADDRESS;
  }

}  // namespace libp2p::multi::converters
