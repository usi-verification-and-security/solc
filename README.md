## Solicitous, the CHC verifier for Solidity contracts

Solicitous is a module of the SMTChecker component of the Solidity compiler. For build instructions please follow the official repository (https://github.com/ethereum/solidity). This is the implementation used in the experiments of our ISoLA 2020 paper, active develepment of Solicitous is done in the official repository under the branches prefixed with `smt_`

To enable SMTChecker add `pragma experimental SMTChecker;` to the source file being checked, while having Z3 installed. Detailed information can be found in the official documentation (https://solidity.readthedocs.io/en/latest/security-considerations.html?#formal-verification).
