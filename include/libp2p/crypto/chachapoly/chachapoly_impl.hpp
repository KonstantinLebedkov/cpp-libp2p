/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <openssl/evp.h>
#include <libp2p/crypto/chachapoly.hpp>
#include <libp2p/log/logger.hpp>

namespace libp2p::crypto::chachapoly {

  class ChaCha20Poly1305Impl : public ChaCha20Poly1305 {
   public:
    explicit ChaCha20Poly1305Impl(Key key);

    outcome::result<Bytes> encrypt(const Nonce &nonce,
                                   BytesIn plaintext,
                                   BytesIn aad) override;

    outcome::result<Bytes> decrypt(const Nonce &nonce,
                                   BytesIn ciphertext,
                                   BytesIn aad) override;

   private:
    outcome::result<void> init(EVP_AEAD_CTX *ctx, bool encrypt);

    const Key key_;
    const EVP_AEAD *aead_;
    const size_t overhead_;
    libp2p::log::Logger log_ = libp2p::log::createLogger("ChaChaPoly");
  };

}  // namespace libp2p::crypto::chachapoly
