1. Create your vhdl file
2. Create your testbench file
3. Check syntax error by following command for both vhdl file and testbench vhdl file
   ghdl -s filename.vhd
4. After no syntax error you can compile the vhdl file and testbench file by following command
   ghdl -a filename.vhd
5. Now elaborate the compiled object by following command
   ghdl -e objectname

6. Now run the object using following command
7. ghdl -r objectname --vcd=filename.vcd
        here vcdfile  is waveform file that will be generated from running testbench object.

8. After waveform generation you can open the vcd file in gtkwave waveform viewer
   
