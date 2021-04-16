# Test Plan

## High Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P | Actual Out | Type of Test|
|-|-|-|-|-|-|
| HTP01 | Check the data being entered to file | File Pointer,Employee Name,Age,Salary,ID |  Addition of details to file| PASS | Technical |
| HTP02 | Delete data specified from File | File Pointer,Employee Name |  | Removal of name from file | Technical |
| HTP03 | Modify data specified to File | File Pointer,Employee Name |  | Modification of details from file | Technical |
| HTP04 | Read data from File | File Pointer |  | Display all detais in the file | Technical |
| HTP03 | Display of file without any redundency | Solution Data | File or invoke a program | PASS | Requirement Based|

## Low Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P | Actual Out | Type of Test|
|-|-|-|-|-|-|
| L_01| Check if ID already  exist | Account ID,  File pointer| Redundancy removed        | PASS       | Technical    |
| L_02    | Read actual input and avoid garbage data       | File pointer to  file.                   | Reduced most of garbage values being generated| FAILED     | Technical    |
| L_03    | While reading display no record found if no data exist                                | Incorrect data | Displayed required output       | PASS        | Requirement  |
| L_04    | If Employee ID is not  present display a  message stating that  No Account can  be found.   | Employee nmae should  be provided.|  Dispaly all details  of particular  Employee name. | PASS       | Technical    |