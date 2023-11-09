/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <libp2p/common/types.hpp>
#include <qtils/outcome.hpp>

namespace libp2p::multi::converters {

  /**
   * Converts a tcp part of a multiaddress (a port)
   * to bytes representation as a hex string
   */
  class TcpConverter {
   public:
    [[deprecated("Use `common::hex_lower(addressToBytes(...))` instead")]]  //
    static outcome::result<std::string>
    addressToHex(std::string_view addr);

    static outcome::result<Bytes> addressToBytes(std::string_view addr);
  };

}  // namespace libp2p::multi::converters
