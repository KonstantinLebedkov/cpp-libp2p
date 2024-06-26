/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <libp2p/protocol/kademlia/message.hpp>

namespace libp2p::protocol::kademlia {

  class Session;

  class ResponseHandler {
   public:
    virtual ~ResponseHandler() = default;

    /// @returns timeout for response waiting
    virtual Time responseTimeout() const = 0;

    /// Check if message is accorded to request
    virtual bool match(const Message &msg) const = 0;

    /// Tries to apply @param res, @returns true if success
    virtual void onResult(const std::shared_ptr<Session> &session,
                          outcome::result<Message> msg_res) = 0;
  };

}  // namespace libp2p::protocol::kademlia
