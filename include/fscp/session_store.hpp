/*
 * libfscp - C++ portable OpenSSL cryptographic wrapper library.
 * Copyright (C) 2010-2011 Julien Kauffmann <julien.kauffmann@freelan.org>
 *
 * This file is part of libfscp.
 *
 * libfscp is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libfscp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libfscp in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file session_store.hpp
 * \author Julien Kauffmann <julien.kauffmann@freelan.org>
 * \brief An session store class.
 */

#ifndef FSCP_SESSION_STORE_HPP
#define FSCP_SESSION_STORE_HPP

#include <boost/array.hpp>

#include <stdint.h>

namespace fscp
{
	/**
	 * \brief An session store class.
	 */
	class session_store
	{
		public:

      /**
       * \brief The session number type.
       */
      typedef uint32_t session_number_type;

      /**
       * \brief The key length.
       */
      static const size_t KEY_LENGTH = 32;

      /**
       * \brief The iv length.
       */
      static const size_t IV_LENGTH = 16;

			/**
			 * \brief The key type.
			 */
			typedef boost::array<uint8_t, KEY_LENGTH> key_type;

			/**
			 * \brief The iv type.
			 */
			typedef boost::array<uint8_t, IV_LENGTH> iv_type;

			/**
			 * \brief Create a new session store.
       * \param session_number The session number.
			 * \param sig_key The signature key.
			 * \param enc_key The encryption key.
       * \param iv The initialization vector.
			 */
			session_store(session_number_type session_number, key_type sig_key, key_type enc_key, iv_type iv);

      /**
       * \brief Get the session number.
       * \return The session number.
       */
      session_number_type session_number() const;

			/**
			 * \brief Get the signature key.
			 * \return The signature key.
			 */
			key_type signature_key() const;

			/**
			 * \brief Get the encryption key.
			 * \return The encryption key.
			 */
			key_type encryption_key() const;

      /**
       * \brief Get the initialization vector.
       * \return The initialization vector.
       */
      iv_type initialization_vector() const;

		private:

      session_number_type m_session_number;
      key_type m_sig_key;
      key_type m_enc_key;
      iv_type m_iv;
	};

	inline session_store::session_store(session_number_type _session_number, key_type sig_key, key_type enc_key, iv_type iv) :
    m_session_number(_session_number),
    m_sig_key(sig_key),
    m_enc_key(enc_key),
    m_iv(iv)
	{
	}

  inline session_store::session_number_type session_store::session_number() const
  {
    return m_session_number;
  }

	inline session_store::key_type session_store::signature_key() const
	{
		return m_sig_key;
	}

	inline session_store::key_type session_store::encryption_key() const
	{
		return m_enc_key;
	}

  inline session_store::iv_type session_store::initialization_vector() const
  {
    return m_iv;
  }
}

#endif /* FSCP_SESSION_STORE_HPP */
