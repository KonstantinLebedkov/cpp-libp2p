/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <string>

#include <boost/optional.hpp>

#include <libp2p/common/types.hpp>

namespace libp2p::multi {

  /**
   * @class Encodes and decodes unsigned integers into and from
   * variable-length byte arrays using LEB128 algorithm.
   */
  class UVarint {
   public:
    /**
     * Constructs a varint from an unsigned integer 'number'
     * @param number
     */
    explicit UVarint(uint64_t number);

    /**
     * Constructs a varint from an array of raw bytes, which are
     * meant to be an already encoded unsigned varint
     * @param varint_bytes an array of bytes representing an unsigned varint
     */
    explicit UVarint(BytesIn varint_bytes);

    /**
     * Constructs a varint from an array of raw bytes, which beginning may or
     * may not be an encoded varint
     * @param varint_bytes an array of bytes, possibly representing an unsigned
     * varint
     */
    static boost::optional<UVarint> create(BytesIn varint_bytes);

    /**
     * Converts a varint back to a usual unsigned integer.
     * @return an integer previously encoded to the varint
     */
    uint64_t toUInt64() const;

    /**
     * @return an array view to raw bytes of the stored varint
     */
    BytesIn toBytes() const &;

    /// Disable to return span to inner data of temporary object
    BytesIn toBytes() const && = delete;

    const std::vector<uint8_t> &toVector() const;

    /**
     * Assigns the varint to an unsigned integer, encoding the latter
     * @param n the integer to encode and store
     * @return this varint
     */
    UVarint &operator=(uint64_t n);

    bool operator==(const UVarint &r) const;
    bool operator!=(const UVarint &r) const;
    bool operator<(const UVarint &r) const;

    /**
     * @return the number of bytes currently stored in a varint
     */
    size_t size() const;

    /**
     * @param varint_bytes an array with a raw byte representation of a varint
     * @return the size of the varint stored in the array, if its content is a
     * valid varint. Otherwise, the result is undefined
     */
    static size_t calculateSize(BytesIn varint_bytes);

   private:
    /// private ctor for unsafe creation
    UVarint(BytesIn varint_bytes, size_t varint_size);

    std::vector<uint8_t> bytes_{};
  };

}  // namespace libp2p::multi
