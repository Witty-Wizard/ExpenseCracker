Implementing Dynamic Structrures in C
=====================================

I have to create an GUI for the user to manage a ledger and also able to dynamically add columns to the ledger.

Originally I thought of using Static structures:

.. code-block :: c
   typedef struct header_s{
   uint id;
   uint date;
   char* description;
   uint amount;
   enum trans_type;
   enum category;
   char* note;
   } struct header_t

