library ieee;
use ieee.std_logic_1164.all;
entity tb_andgate is
end tb_andgate;

architecture behav of tb_andgate is
component andgate is
port( 
	a,b:in std_logic;
	c:out std_logic
	);
end component;
signal a, b, c: std_logic;
begin 
a1:andgate port map(a,b,c);
process
begin
 a<='1';
 b<='1';
 wait for 1 ns;
 a<='0';
 b<='1';
 wait for 1 ns;
 a<='0';
 b<='1';
 wait for 1 ns;
 a<='0';
 b<='0';
 wait for 1 ns;
 wait;
end process; 
end behav;