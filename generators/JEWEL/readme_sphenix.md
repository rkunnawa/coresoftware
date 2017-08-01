README file for running JEWEL in sPHENIX 

1. First run make inorder to create the jewel executable (jewel-2.2.0-vac for pp and jewel-2.2.0-simple for AuAu) 
   Note: This is a preliminary setup, in that we hope to have jewel executables installed in /opt/sphenix/core
2. Modify te parameter file to your need (examples are available in params.example.dat and params_auau.example.dat)
   Additional parameters can be found in the jewel manuals 1608.03099 and 1311.0048 
3. Run jewel as follows 
   $ ./jewel-2.2.0-vac parameterfile.dat 
   Note: We will also be providing condor run scripts with functionality for parallel jewel production 

