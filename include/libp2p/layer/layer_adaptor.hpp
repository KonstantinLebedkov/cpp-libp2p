/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <memory>

#include <libp2p/connection/layer_connection.hpp>

namespace libp2p::layer {
  /**
   * Strategy to upgrade connections to next-layer
   */
  struct LayerAdaptor {
    using LayerConnCallbackFunc = std::function<void(
        outcome::result<std::shared_ptr<connection::LayerConnection>>)>;

    virtual ~LayerAdaptor() = default;

    virtual multi::Protocol::Code getProtocol() const = 0;

    /**
     * Make a next-layer connection from the current-layer one, using this
     * adaptor
     * @param conn - connection to be upgraded
     * @param cb - callback with an upgraded connection or error
     */
    virtual void upgradeInbound(
        std::shared_ptr<connection::LayerConnection> conn,
        LayerConnCallbackFunc cb) const = 0;

    /**
     * Make a next-layer connection from the current-layer one, using this
     * adaptor
     * @param conn - connection to be upgraded
     * @param cb - callback with an upgraded connection or error
     */
    virtual void upgradeOutbound(
        const multi::Multiaddress &address,
        std::shared_ptr<connection::LayerConnection> conn,
        LayerConnCallbackFunc cb) const = 0;
  };
}  // namespace libp2p::layer
