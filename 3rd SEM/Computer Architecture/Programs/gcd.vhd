library ieee;
use ieee.std_logic_1164.all;

entity gcd is 
	port(
		clk: in std_logic;
		clr: in std_logic;
		go: in std_logic;
		xin: in std_logic_vector(3 downto 0);
		yin: in std_logic_vector(3 downto 0);
		gcd_out: out std_logic_vector(3 downto 0));

end gcd;

architecture gcd of gcd is
	component gcd_datapath
	port(
		clk: in std_logic;
		clr: in std_logic;
		xmsel: in std_logic;
		ymsel: in std_logic;
		xld: in std_logic;
		yld: in std_logic;
		gld: in std_logic;
		xin: in std_logic_vector(3 downto 0);
		yin: in std_logic_vector(3 downto 0);
		gcd: out std_logic_vector(3 downto 0);
		eqflg: out std_logic;
		ltflg: out std_logic);
	end component;
	
	component gcd_control
	port(
		clk: in std_logic;
		clr: in std_logic;
		go: in std_logic;
		eqflg: in std_logic;
		ltflg: in std_logic;
		xmsel: out std_logic;
		ymsel: out std_logic;
		xld: out std_logic;
		yld: out std_logic;
		gld: out std_logic);
	end component;
	
signal eqflg, ltflg, xmsel, ymsel:std_logic;
signal xld,yld,gld: std_logic;

begin
U1: gcd_datapath
	port map( clk=>clk, clr=>clr, xmsel=>xmsel,ymsel=>ymsel,
		xld=>xld, yld=>yld,gld=>gld, xin=> xin, yin=>yin, 
		gcd=>gcd_out,eqflg=>eqflg,ltflg=>ltflg);
U2: gcd_control
	port map(clk=>clk, clr=>clr,go=>go, eqflg=>eqflg,ltflg=>ltflg,xmsel=>xmsel,ymsel=>ymsel,
	xld=>xld,yld=>yld,gld=>gld);

end gcd;
