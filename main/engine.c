#include "engine.h"

OWASPVulns      ProfileA01            = {"A01", "Broken Access Control"};
OWASPBaseAction ProfileA01_Attack1    = {"CWE-25", "Path Traversal"};
OWASPBaseAction ProfileA01_A1Response = {"CWE-25R", "Validate Input"};
OWASPBaseAction ProfileA01_Attack2    = {"CWE-352", "Cross-Site Request Forgery"};
OWASPBaseAction ProfileA01_A2Response = {"CWE-352R", "Anti-CSRF"};
OWASPAction     A01Action1            = { &ProfileA01_Attack1, &ProfileA01_A1Response };
OWASPAction     A01Action2            = { &ProfileA01_Attack2, &ProfileA01_A2Response };
OWASPProfile    OWASPA01              = { &ProfileA01, &A01Action1, &A01Action2 };

OWASPVulns      ProfileA02            = {"A02", "Cryptographic Failures"};
OWASPBaseAction ProfileA02_Attack1    = {"CWE-261", "Weak Encoding Password"};
OWASPBaseAction ProfileA02_A1Response = {"CWE-261R", "128 bits Encryption"};
OWASPBaseAction ProfileA02_Attack2    = {"CWE-319", "Cleartext Transmission"};
OWASPBaseAction ProfileA02_A2Response = {"CWE-319R", "SSL/Cryptographic"};
OWASPAction     A02Action1            = { &ProfileA02_Attack1, &ProfileA02_A1Response };
OWASPAction     A02Action2            = { &ProfileA02_Attack2, &ProfileA02_A2Response };
OWASPProfile    OWASPA02              = { &ProfileA02, &A02Action1, &A02Action2 };

OWASPVulns      ProfileA03            = {"A03", "Injection"};
OWASPBaseAction ProfileA03_Attack1    = {"CWE-20", "Improper Input Validation"};
OWASPBaseAction ProfileA03_A1Response = {"CWE-20R", "Client/Server Validation"};
OWASPBaseAction ProfileA03_Attack2    = {"CWE-89", "SQL Injection"};
OWASPBaseAction ProfileA03_A2Response = {"CWE-89R", "Isolated account"};
OWASPAction     A03Action1            = { &ProfileA03_Attack1, &ProfileA03_A1Response };
OWASPAction     A03Action2            = { &ProfileA03_Attack2, &ProfileA03_A2Response };
OWASPProfile    OWASPA03              = { &ProfileA03, &A03Action1, &A03Action2 };

OWASPVulns      ProfileA04            = {"A04", "Insecure Design"};
OWASPBaseAction ProfileA04_Attack1    = {"CWE-256", "Unprotected Storage of Credentials"};
OWASPBaseAction ProfileA04_A1Response = {"CWE-256R", "Hashes of password"};
OWASPBaseAction ProfileA04_Attack2    = {"CWE-434", "Unrestricted Upload"};
OWASPBaseAction ProfileA04_A2Response = {"CWE-434R", "Generate Hashes of Files"};
OWASPAction     A04Action1            = { &ProfileA04_Attack1, &ProfileA04_A1Response };
OWASPAction     A04Action2            = { &ProfileA04_Attack2, &ProfileA04_A2Response };
OWASPProfile    OWASPA04              = { &ProfileA04, &A04Action1, &A04Action2 };

OWASPVulns      ProfileA05            = {"A05", "Security Misconfiguration"};
OWASPBaseAction ProfileA05_Attack1    = {"CWE-260", "Password in Configuration File"};
OWASPBaseAction ProfileA05_A1Response = {"CWE-260R", "Static Application Security Testing"};
OWASPBaseAction ProfileA05_Attack2    = {"CWE-315", "Cleartext storage"};
OWASPBaseAction ProfileA05_A2Response = {"CWE-315R", "Encrypt Information"};
OWASPAction     A05Action1            = { &ProfileA05_Attack1, &ProfileA05_A1Response };
OWASPAction     A05Action2            = { &ProfileA05_Attack2, &ProfileA05_A2Response };
OWASPProfile    OWASPA05              = { &ProfileA05, &A05Action1, &A05Action2 };

OWASPVulns      ProfileA06            = {"A06", "Vulnerable outdated Commponents"};
OWASPBaseAction ProfileA06_Attack1    = {"CWE-937", "Using Commponents with Known Vulns"};
OWASPBaseAction ProfileA06_A1Response = {"CWE-937R", "Update Version"};
OWASPBaseAction ProfileA06_Attack2    = {"CWE-319", "Use of Unmaintained Commponents"};
OWASPBaseAction ProfileA06_A2Response = {"CWE-319R", "Change Component"};
OWASPAction     A06Action1            = { &ProfileA06_Attack1, &ProfileA06_A1Response };
OWASPAction     A06Action2            = { &ProfileA06_Attack2, &ProfileA06_A2Response };
OWASPProfile    OWASPA06              = { &ProfileA06, &A06Action1, &A06Action2 };

OWASPVulns      ProfileA07            = {"A07", "Identification Authentication Failures"};
OWASPBaseAction ProfileA07_Attack1    = {"CWE-259", "Use of Hardcoded Credentials"};
OWASPBaseAction ProfileA07_A1Response = {"CWE-259R", "Store password outside of code"};
OWASPBaseAction ProfileA07_Attack2    = {"CWE-307", "Improper Handler Authentication Attempts"};
OWASPBaseAction ProfileA07_A2Response = {"CWE-307R", "Implemment Lockout Mechanism"};
OWASPAction     A07Action1            = { &ProfileA07_Attack1, &ProfileA07_A1Response };
OWASPAction     A07Action2            = { &ProfileA07_Attack2, &ProfileA07_A2Response };
OWASPProfile    OWASPA07              = { &ProfileA07, &A07Action1, &A07Action2 };

OWASPVulns      ProfileA08            = {"A08", "Software and Data Integrity Failures"};
OWASPBaseAction ProfileA08_Attack1    = {"CWE-426", "Untrusted Search Path"};
OWASPBaseAction ProfileA08_A1Response = {"CWE-426R", "Use function that require explicit path"};
OWASPBaseAction ProfileA08_Attack2    = {"CWE-494", "Download of Code Without Integrity Check"};
OWASPBaseAction ProfileA08_A2Response = {"CWE-494R", "Implement Integrity Check"};
OWASPAction     A08Action1            = { &ProfileA08_Attack1, &ProfileA08_A1Response };
OWASPAction     A08Action2            = { &ProfileA08_Attack2, &ProfileA08_A2Response };
OWASPProfile    OWASPA08              = { &ProfileA08, &A08Action1, &A08Action2 };

OWASPVulns      ProfileA09            = {"A09", "Security Logging and Monitoring Failures"};
OWASPBaseAction ProfileA09_Attack1    = {"CWE-532", "Insertion of Sensitive Information"};
OWASPBaseAction ProfileA09_A1Response = {"CWE-532R", "Protect Log files from unauthorized access"};
OWASPBaseAction ProfileA09_Attack2    = {"CWE-778", "Insufficient Logging"};
OWASPBaseAction ProfileA09_A2Response = {"CWE-778R", "Centralized logging mmechanism"};
OWASPAction     A09Action1            = { &ProfileA09_Attack1, &ProfileA09_A1Response };
OWASPAction     A09Action2            = { &ProfileA09_Attack2, &ProfileA09_A2Response };
OWASPProfile    OWASPA09              = { &ProfileA09, &A09Action1, &A09Action2 };

OWASPVulns      ProfileA10            = {"A10", "Server Side Request Forgery"};
OWASPBaseAction ProfileA10_Attack1    = {"CWE-918", "Server-Side Request Forgery"};
OWASPBaseAction ProfileA10_A1Response = {"CWE-918R", "Restrict access to internal network"};
OWASPAction     A10Action1            = { &ProfileA10_Attack1, &ProfileA10_A1Response };
OWASPProfile    OWASPA10              = { &ProfileA10, &A10Action1, &A10Action1 };

const OWASPVulns vulns[] = {
    {"A01", "Broken Access Control"},
    {"A02", "Cryptographic Failures"},
    {"A03", "Injection"},
    {"A04", "Insecure Design"},
    {"A05", "Security Misconfiguration"},
    {"A06", "Vulnerable outdated Components"},
    {"A07", "Identification Authentication Failures"},
    {"A08", "Software and Data Integrity Failures"},
    {"A09", "Security Logging and Monitoring Failures"},
    {"A10", "Server Side Request Forgery"}
};

const OWASPBaseAction baseActions[] = {
{"CWE-25", "Path Traversal"},
{"CWE-25R", "Validate Input"},
{"CWE-352", "Cross-Site Request Forgery"},
{"CWE-352R", "Anti-CSRF"},
{"CWE-261", "Weak Encoding Password"},
{"CWE-261R", "128 bits Encryption"},
{"CWE-319", "Cleartext Transmission"},
{"CWE-319R", "SSL/Cryptographic"},
{"CWE-20", "Improper Input Validation"},
{"CWE-20R", "Client/Server Validation"},
{"CWE-89", "SQL Injection"},
{"CWE-89R", "Isolated account"},
{"CWE-256", "Unprotected Storage of Credentials"},
{"CWE-256R", "Hashes of password"},
{"CWE-434", "Unrestricted Upload"},
{"CWE-434R", "Generate Hashes of Files"},
{"CWE-260", "Password in Configuration File"},
{"CWE-260R", "Static Application Security Testing"},
{"CWE-315", "Cleartext storage"},
{"CWE-315R", "Encrypt Information"},
{"CWE-937", "Using Commponents with Known Vulns"},
{"CWE-937R", "Update Version"},
{"CWE-319", "Use of Unmaintained Commponents"},
{"CWE-319R", "Change Component"},
{"CWE-259", "Use of Hardcoded Credentials"},
{"CWE-259R", "Store password outside of code"},
{"CWE-307", "Improper Handler Authentication Attempts"},
{"CWE-307R", "Implemment Lockout Mechanism"},
{"CWE-426", "Untrusted Search Path"},
{"CWE-426R", "Use function that require explicit path"},
{"CWE-494", "Download of Code Without Integrity Check"},
{"CWE-494R", "Implement Integrity Check"},
{"CWE-532", "Insertion of Sensitive Information"},
{"CWE-532R", "Protect Log files from unauthorized access"},
{"CWE-778", "Insufficient Logging"},
{"CWE-778R", "Centralized logging mmechanism"},
{"CWE-918", "Server-Side Request Forgery"},
{"CWE-918R", "Restrict access to internal network"}
};

const OWASPAction actions[] = {
{ &baseActions[0], &baseActions[1] }, //CWE-25, CWE-25R
{ &baseActions[2], &baseActions[3] }, //CWE-352, CWE-352R
{ &baseActions[4], &baseActions[5] }, //CWE-261, CWE-261R
{ &baseActions[6], &baseActions[7] }, //CWE-319, CWE-319R
{ &baseActions[8], &baseActions[9] }, //CWE-20, CWE-20R
{ &baseActions[10], &baseActions[11] }, //CWE-89, CWE-89R
{ &baseActions[12], &baseActions[13] }, //CWE-256, CWE-256R
{ &baseActions[14], &baseActions[15] }, //CWE-434, CWE-434R
{ &baseActions[16], &baseActions[17] }, //CWE-260, CWE-260R
{ &baseActions[18], &baseActions[19] }, //CWE-315, CWE-315R
{ &baseActions[20], &baseActions[21] }, //CWE-937, CWE-937R
{ &baseActions[22], &baseActions[23] }, //CWE-319, CWE-319R
{ &baseActions[24], &baseActions[25] }, //CWE-259, CWE-259R
{ &baseActions[26], &baseActions[27] }, //CWE-307, CWE-307R
{ &baseActions[28], &baseActions[29] }, //CWE-426, CWE-426R
{ &baseActions[30], &baseActions[31] }, //CWE-494, CWE-494R
{ &baseActions[32], &baseActions[33] }, //CWE-532, CWE-532R
{ &baseActions[34], &baseActions[35] }, //CWE-778, CWE-778R
{ &baseActions[36], &baseActions[37] }, //CWE-918, CWE-918R
};

const OWASPProfile profiles[] = {
{ &vulns[0], &actions[0], &actions[1] }, // A01
{ &vulns[1], &actions[2], &actions[3] }, // A02
{ &vulns[2], &actions[4], &actions[5] }, // A03
{ &vulns[3], &actions[6], &actions[7] }, // A04
{ &vulns[4], &actions[8], &actions[9] }, // A05
{ &vulns[5], &actions[10], &actions[11] }, // A06
{ &vulns[6], &actions[12], &actions[13] }, // A07
{ &vulns[7], &actions[14], &actions[15] }, // A08
{ &vulns[8], &actions[16], &actions[17] }, // A09
{ &vulns[9], &actions[18], &actions[19] } // A10
};

OWASPProfile* getOWASPProfile(int index) {
    if (index >= 0 && index < sizeof(profiles) / sizeof(profiles[0])) {
        return &profiles[index];
    }
    return &profiles[0];
}

// const OWASPVulns vulns[] = {
//     {"A01", "Broken Access Control"},
//     {"A02", "Cryptographic Failures"},
//     {"A03", "Injection"},
//     {"A04", "Insecure Design"},
//     {"A05", "Security Misconfiguration"},
//     {"A06", "Vulnerable outdated Commponents"},
//     {"A07", "Identification Authentication Failures"},
//     {"A08", "Software and Data Integrity Failures"},
//     {"A09", "Security Logging and Monitoring Failures"},
//     {"A10", "Server Side Request Forgery"},
// };

// const OWASPBaseAction baseActions[] = {
//     {"CWE-25", "Path Traversal"},
//     {"CWE-25R", "Validate Input"},
//     {"CWE-352", "Cross-Site Request Forgery"},
//     {"CWE-352R", "Anti-CSRF"},
//     {"CWE-261", "Weak Encoding Password"},
//     {"CWE-261R", "128 bits Encryption"},
//     {"CWE-319", "Cleartext Transmission"},
//     {"CWE-319R", "SSL/Cryptographic"},
//     {"CWE-20", "Improper Input Validation"},
//     {"CWE-20R", "Client/Server Validation"},
//     {"CWE-89", "SQL Injection"},
//     {"CWE-89R", "Isolated account"},
//     {"CWE-256", "Unprotected Storage of Credentials"},
//     {"CWE-256R", "Hashes of password"},
//     {"CWE-434", "Unrestricted Upload"},
//     {"CWE-434R", "Generate Hashes of Files"},
//     {"CWE-260", "Password in Configuration File"},
//     {"CWE-260R", "Static Application Security Testing"},
//     {"CWE-315", "Cleartext storage"},
//     {"CWE-315R", "Encrypt Information"},
//     {"CWE-937", "Using Commponents with Known Vulns"},
//     {"CWE-937R", "Update Version"},
//     {"CWE-307", "Improper Handler Authentication Attempts"},
//     {"CWE-307R", "Implemment Lockout Mechanism"},
//     {"CWE-259", "Use of Hardcoded Credentials"},
//     {"CWE-259R", "Store password outside of code"},
//     {"CWE-426", "Untrusted Search Path"},
//     {"CWE-426R", "Use function that require explicit path"},
//     {"CWE-494", "Download of Code Without Integrity Check"},
//     {"CWE-494R", "Implement Integrity Check"},
//     {"CWE-532", "Insertion of Sensitive Information"},
//     {"CWE-532R", "Protect Log files from unauthorized access"},
//     {"CWE-778", "Insufficient Logging"},
//     {"CWE-778R", "Centralized logging mmechanism"},
//     {"CWE-918", "Server-Side Request Forgery"},
//     {"CWE-918R", "Restrict access to internal network"},
// };

// const OWASPAction actions[] = {
//     { &baseActions[0], &baseActions[1] },
//     { &baseActions[2], &baseActions[3] },
//     { &baseActions[4], &baseActions[5] },
//     { &baseActions[6], &baseActions[7] },
//     { &baseActions[8], &baseActions[9] },
//     { &baseActions[10], &baseActions[11] },
//     { &baseActions[12], &baseActions[13] },
//     { &baseActions[14], &baseActions[15] },
//     { &baseActions[16], &baseActions[17] },
//     { &baseActions[18], &baseActions[19] },
//     { &baseActions[20], &baseActions[21] },
//     { &baseActions[22], &baseActions[23] },
//     { &baseActions[24], &baseActions[25] },
//     { &baseActions[26], &baseActions[27] },
//     { &baseActions[28], &baseActions[29] },
//     { &baseActions[30], &baseActions[31] },
//     { &baseActions[32], &baseActions[33] },
//     { &baseActions[34], &baseActions[35] },
//     { &baseActions[36], &baseActions[37] },
//     { &baseActions[38], &baseActions[39] },
// };

// const OWASPProfile OWASPProfilesArray[] = {
//     { &vulns[0], &actions[0], &actions[1] },
//     { &vulns[1], &actions[2], &actions[3] },
//     { &vulns[2], &actions[4], &actions[5] },
//     { &vulns[3], &actions[6], &actions[7] },
//     { &vulns[4], &actions[8], &actions[9] },
//     { &vulns[5], &actions[10], &actions[11] },
//     { &vulns[6], &actions[12], &actions[13] },
//     { &vulns[7], &actions[14], &actions[15] },
//     { &vulns[8], &actions[16], &actions[17] },
//     { &vulns[9], &actions[18], &actions[19] },
// };