/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <boost/asio.hpp>
#include <libp2p/transport/tcp/tcp_connection.hpp>
#include <libp2p/transport/transport_listener.hpp>
#include <libp2p/transport/upgrader.hpp>

namespace libp2p::transport {

  /**
   * @brief TCP Server (Listener) implementation.
   */
  class TcpListener : public TransportListener,
                      public std::enable_shared_from_this<TcpListener> {
   public:
    ~TcpListener() override = default;

    TcpListener(boost::asio::io_context &context,
                std::shared_ptr<Upgrader> upgrader,
                TransportListener::HandlerFunc handler);

    outcome::result<void> listen(const multi::Multiaddress &address) override;

    bool canListen(const multi::Multiaddress &ma) const override;

    outcome::result<multi::Multiaddress> getListenMultiaddr() const override;

    bool isClosed() const override;

    outcome::result<void> close() override;

   private:
    boost::asio::io_context &context_;
    std::shared_ptr<Upgrader> upgrader_;
    TransportListener::HandlerFunc handle_;

    boost::asio::ip::tcp::acceptor acceptor_;

    ProtoAddrVec layers_;

    void doAccept();
  };

}  // namespace libp2p::transport
