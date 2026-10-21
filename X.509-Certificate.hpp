An X.509 certificate is a standardized digital certificate used in TLS/SSL, HTTPS, VPNs, code signing, email encryption, and many other security protocols. 
It binds a public key to the identity of an entity (person, server, or organization).

X.509 Certificate
│
├── Version
├── Serial Number
├── Signature Algorithm
├── Issuer
├── Validity
│   ├── Not Before
│   └── Not After
├── Subject
├── Subject Public Key Info
│   ├── Public Key Algorithm
│   └── Public Key
├── Extensions
│   ├── Subject Alternative Name (SAN)
│   ├── Key Usage
│   ├── Extended Key Usage
│   ├── Basic Constraints
│   ├── Authority Key Identifier
│   ├── Subject Key Identifier
│   └── CRL Distribution Points / OCSP
└── Digital Signature

1. Version
Specifies the X.509 version.

Common values:
- Version 1
- Version 2
- Version 3 (most common today)
Version 3 supports extensions.
2. Serial Number
A unique number assigned by the Certificate Authority (CA).

Example:
Serial Number:
4F:12:AE:77:90:11

Used for:
- Revocation
- Tracking certificates
3. Signature Algorithm
Indicates which algorithm the CA used to sign the certificate.

Examples:
- RSA with SHA-256
- ECDSA with SHA-384
- RSA-PSS
Example:
sha256WithRSAEncryption

4. Issuer
Identifies the Certificate Authority that issued the certificate.

Example:
Issuer:
CN = DigiCert Global Root CA
O  = DigiCert Inc
C  = US

5. Validity Period
Defines the certificate's lifetime.

Example:
Not Before:
Jan 1 2026

Not After:
Jan 1 2027

If the current date is outside this range, the certificate is considered invalid.
6. Subject
Represents the entity the certificate belongs to.

Example:
CN = www.example.com
O  = Example Inc
L  = Delhi
C  = IN

For websites, the Common Name (CN) is often supplemented or replaced by the Subject Alternative Name (SAN).
7. Subject Public Key Info
Contains the public key and the algorithm used.

Example:
Algorithm:
RSA

Public Key:
2048 bits

Or:
Algorithm:
ECDSA

Curve:
P-256

The corresponding private key is not included in the certificate.
8. Extensions (Version 3)
Extensions add important information about how the certificate should be used.
Subject Alternative Name (SAN)
Lists all valid hostnames or IP addresses.

Example:
DNS:example.com
DNS:www.example.com
DNS:api.example.com

Modern browsers verify hostnames against the SAN extension.
Key Usage
Specifies allowed cryptographic operations.

Examples:
Digital Signature
Key Encipherment
Key Agreement
Certificate Sign
CRL Sign

Extended Key Usage (EKU)
Specifies intended purposes.

Examples:
TLS Web Server Authentication
TLS Web Client Authentication
Code Signing
Email Protection

Basic Constraints
Indicates whether the certificate can act as a CA.

Example:
CA: FALSE

or
CA: TRUE

Subject Key Identifier (SKI)
A unique identifier for the subject's public key.

Used to build certificate chains.
Authority Key Identifier (AKI)
Identifies the issuing CA's public key.

Used to locate the issuer certificate.
CRL Distribution Points
Provides URLs for downloading the Certificate Revocation List (CRL).

Example:
http://crl.exampleca.com/root.crl

Authority Information Access (AIA)
Contains URLs for:
- OCSP responders (to check revocation status)
- Issuer certificates
9. Digital Signature
The CA computes a hash of the certificate contents and signs it using the CA's private key.

Verification steps:
1. Hash the certificate data.
2. Decrypt the signature using the CA's public key.
3. Compare the hashes.
4. If they match, the certificate has not been altered and was signed by the CA.
PEM Example
A certificate is commonly stored in PEM format:
-----BEGIN CERTIFICATE-----
MIIF...
...
-----END CERTIFICATE-----

This is Base64-encoded DER (binary) data.
Viewing Certificate Details with OpenSSL
To inspect a certificate:
openssl x509 -in cert.pem -text -noout

Typical output includes:
Certificate:
    Data:
        Version: 3
        Serial Number: 0x01A2B3C4
        Signature Algorithm: sha256WithRSAEncryption

        Issuer:
            CN=DigiCert Global Root CA

        Validity
            Not Before: Jan 1 00:00:00 2026 GMT
            Not After : Jan 1 00:00:00 2027 GMT

        Subject:
            CN=www.example.com

        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
            RSA Public-Key: (2048 bit)

        X509v3 extensions:
            Subject Alternative Name:
                DNS:www.example.com
                DNS:example.com

            Key Usage:
                Digital Signature
                Key Encipherment

            Extended Key Usage:
                TLS Web Server Authentication

            Basic Constraints:
                CA:FALSE

    Signature Algorithm:
        sha256WithRSAEncryption

    Signature Value:
        3f:8c:...

Interview Summary
Field	Purpose
Version	X.509 format version (typically v3)
Serial Number	Unique identifier assigned by the CA
Signature Algorithm	Algorithm used by the CA to sign the certificate
Issuer	Certificate Authority that issued the certificate
Validity	Start and expiration dates
Subject	Identity of the certificate owner
Public Key	The subject's public key and algorithm
Extensions	Usage restrictions, SANs, CA status, revocation information, etc.
Digital Signature	Ensures authenticity and integrity of the certificate


Key interview point: An X.509 certificate does not contain the private key. It contains the subject's public key, identity information, validity period, extensions, and the CA's digital signature, which allows others to verify that the certificate is authentic and has not been modified.
