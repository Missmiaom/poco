//
// CipherImpl.h
//
// $Id: //poco/1.4/Crypto/include/Poco/Crypto/CipherImpl.h#1 $
//
// Library: Crypto
// Package: Cipher
// Module:  CipherImpl
//
// Definition of the CipherImpl class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Crypto_CipherImpl_INCLUDED
#define Crypto_CipherImpl_INCLUDED


#include "Poco/Crypto/Crypto.h"
#include "Poco/Crypto/Cipher.h"
#include "Poco/Crypto/CipherKey.h"

#include <openssl/evp.h>


namespace Poco {
namespace Crypto {


class CipherImpl: public Cipher
	/// An implementation of the Cipher class for OpenSSL's crypto library.
{
public:
	CipherImpl(const CipherKey& key);
		/// Creates a new CipherImpl object for the given CipherKey.

	virtual ~CipherImpl();
		/// Destroys the CipherImpl.

	const std::string& name() const;
		/// Returns the name of the cipher.

	CryptoTransform* createEncryptor();
		/// Creates an encrytor object.

	CryptoTransform* createDecryptor();
		/// Creates a decrytor object.

private:
	CipherKey _key;
};


//
// Inlines
//
inline const std::string& CipherImpl::name() const
{
	return _key.name();
}


} } // namespace Poco::Crypto


#endif // Crypto_CipherImpl_INCLUDED
