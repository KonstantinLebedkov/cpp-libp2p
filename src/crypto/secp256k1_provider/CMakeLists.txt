#
# Copyright Quadrivium LLC
# All Rights Reserved
# SPDX-License-Identifier: Apache-2.0
#

libp2p_add_library(p2p_secp256k1_provider
    secp256k1_provider_impl.cpp
    )

target_link_libraries(p2p_secp256k1_provider
    libsecp256k1::secp256k1
    p2p_sha
    p2p_crypto_error
    p2p_crypto_common
    OpenSSL::Crypto
    )
