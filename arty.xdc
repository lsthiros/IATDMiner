## This file is a general .xdc for the ARTY Rev. B
## To use it in a project:
## - uncomment the lines corresponding to used pins
## - rename the used ports (in each line, after get_ports) according to the top level signal names in the project

## Clock signal

set_property -dict {PACKAGE_PIN E3 IOSTANDARD LVCMOS33} [get_ports CLK100MHZ]
create_clock -period 10.000 -name sys_clk_pin -waveform {0.000 5.000} -add [get_ports CLK100MHZ]

##Switches

set_property -dict {PACKAGE_PIN A8 IOSTANDARD LVCMOS33} [get_ports reset]
set_property -dict {PACKAGE_PIN C11 IOSTANDARD LVCMOS33} [get_ports shaReset]
#set_property -dict { PACKAGE_PIN C10   IOSTANDARD LVCMOS33 } [get_ports { sw[2] }]; #IO_L13N_T2_MRCC_16 Sch=sw[2]
#set_property -dict { PACKAGE_PIN A10   IOSTANDARD LVCMOS33 } [get_ports { sw[3] }]; #IO_L14P_T2_SRCC_16 Sch=sw[3]

##RGB LEDs

#set_property -dict { PACKAGE_PIN E1    IOSTANDARD LVCMOS33 } [get_ports { led0_b }]; #IO_L18N_T2_35 Sch=led0_b
#set_property -dict { PACKAGE_PIN F6    IOSTANDARD LVCMOS33 } [get_ports { led0_g }]; #IO_L19N_T3_VREF_35 Sch=led0_g
#set_property -dict { PACKAGE_PIN G6    IOSTANDARD LVCMOS33 } [get_ports { led0_r }]; #IO_L19P_T3_35 Sch=led0_r
#set_property -dict { PACKAGE_PIN G4    IOSTANDARD LVCMOS33 } [get_ports { led1_b }]; #IO_L20P_T3_35 Sch=led1_b
#set_property -dict { PACKAGE_PIN J4    IOSTANDARD LVCMOS33 } [get_ports { led1_g }]; #IO_L21P_T3_DQS_35 Sch=led1_g
#set_property -dict { PACKAGE_PIN G3    IOSTANDARD LVCMOS33 } [get_ports { led1_r }]; #IO_L20N_T3_35 Sch=led1_r
#set_property -dict { PACKAGE_PIN H4    IOSTANDARD LVCMOS33 } [get_ports { led2_b }]; #IO_L21N_T3_DQS_35 Sch=led2_b
#set_property -dict { PACKAGE_PIN J2    IOSTANDARD LVCMOS33 } [get_ports { led2_g }]; #IO_L22N_T3_35 Sch=led2_g
#set_property -dict { PACKAGE_PIN J3    IOSTANDARD LVCMOS33 } [get_ports { led2_r }]; #IO_L22P_T3_35 Sch=led2_r
#set_property -dict { PACKAGE_PIN K2    IOSTANDARD LVCMOS33 } [get_ports { led3_b }]; #IO_L23P_T3_35 Sch=led3_b
#set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { led3_g }]; #IO_L24P_T3_35 Sch=led3_g
#set_property -dict { PACKAGE_PIN K1    IOSTANDARD LVCMOS33 } [get_ports { led3_r }]; #IO_L23N_T3_35 Sch=led3_r

##LEDs

set_property -dict {PACKAGE_PIN H5 IOSTANDARD LVCMOS33} [get_ports resOut]
set_property -dict {PACKAGE_PIN J5 IOSTANDARD LVCMOS33} [get_ports solutionFound]
#set_property -dict { PACKAGE_PIN T9    IOSTANDARD LVCMOS33 } [get_ports { led[2] }]; #IO_L24P_T3_A01_D17_14 Sch=led[6]
#set_property -dict { PACKAGE_PIN T10   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]; #IO_L24N_T3_A00_D16_14 Sch=led[7]

##Buttons

#set_property -dict { PACKAGE_PIN D9    IOSTANDARD LVCMOS33 } [get_ports { btn[0] }]; #IO_L6N_T0_VREF_16 Sch=btn[0]
#set_property -dict { PACKAGE_PIN C9    IOSTANDARD LVCMOS33 } [get_ports { btn[1] }]; #IO_L11P_T1_SRCC_16 Sch=btn[1]
#set_property -dict { PACKAGE_PIN B9    IOSTANDARD LVCMOS33 } [get_ports { btn[2] }]; #IO_L11N_T1_SRCC_16 Sch=btn[2]
#set_property -dict { PACKAGE_PIN B8    IOSTANDARD LVCMOS33 } [get_ports { btn[3] }]; #IO_L12P_T1_MRCC_16 Sch=btn[3]

##Pmod Header JA

set_property -dict {PACKAGE_PIN G13 IOSTANDARD LVCMOS33} [get_ports {bitCount[0]}]
set_property -dict {PACKAGE_PIN B11 IOSTANDARD LVCMOS33} [get_ports {bitCount[1]}]
set_property -dict {PACKAGE_PIN A11 IOSTANDARD LVCMOS33} [get_ports {bitCount[2]}]
set_property -dict {PACKAGE_PIN D12 IOSTANDARD LVCMOS33} [get_ports {bitCount[3]}]
set_property -dict {PACKAGE_PIN D13 IOSTANDARD LVCMOS33} [get_ports slowClkWire]
#set_property -dict { PACKAGE_PIN B18   IOSTANDARD LVCMOS33 } [get_ports { ja[5] }]; #IO_L10P_T1_AD11P_15 Sch=ja[8]
#set_property -dict { PACKAGE_PIN A18   IOSTANDARD LVCMOS33 } [get_ports { ja[6] }]; #IO_L10N_T1_AD11N_15 Sch=ja[9]
#set_property -dict { PACKAGE_PIN K16   IOSTANDARD LVCMOS33 } [get_ports { ja[7] }]; #IO_25_15 Sch=ja[10]

##Pmod Header JB

#set_property -dict { PACKAGE_PIN E15   IOSTANDARD LVCMOS33 } [get_ports { jb[0] }]; #IO_L11P_T1_SRCC_15 Sch=jb_p[1]
#set_property -dict { PACKAGE_PIN E16   IOSTANDARD LVCMOS33 } [get_ports { jb[1] }]; #IO_L11N_T1_SRCC_15 Sch=jb_n[1]
#set_property -dict { PACKAGE_PIN D15   IOSTANDARD LVCMOS33 } [get_ports { jb[2] }]; #IO_L12P_T1_MRCC_15 Sch=jb_p[2]
#set_property -dict { PACKAGE_PIN C15   IOSTANDARD LVCMOS33 } [get_ports { jb[3] }]; #IO_L12N_T1_MRCC_15 Sch=jb_n[2]
#set_property -dict { PACKAGE_PIN J17   IOSTANDARD LVCMOS33 } [get_ports { jb[4] }]; #IO_L23P_T3_FOE_B_15 Sch=jb_p[3]
#set_property -dict { PACKAGE_PIN J18   IOSTANDARD LVCMOS33 } [get_ports { jb[5] }]; #IO_L23N_T3_FWE_B_15 Sch=jb_n[3]
#set_property -dict { PACKAGE_PIN K15   IOSTANDARD LVCMOS33 } [get_ports { jb[6] }]; #IO_L24P_T3_RS1_15 Sch=jb_p[4]
#set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { jb[7] }]; #IO_L24N_T3_RS0_15 Sch=jb_n[4]

##Pmod Header JC

#set_property -dict { PACKAGE_PIN U12   IOSTANDARD LVCMOS33 } [get_ports { jc[0] }]; #IO_L20P_T3_A08_D24_14 Sch=jc_p[1]
#set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33 } [get_ports { jc[1] }]; #IO_L20N_T3_A07_D23_14 Sch=jc_n[1]
#set_property -dict { PACKAGE_PIN V10   IOSTANDARD LVCMOS33 } [get_ports { jc[2] }]; #IO_L21P_T3_DQS_14 Sch=jc_p[2]
#set_property -dict { PACKAGE_PIN V11   IOSTANDARD LVCMOS33 } [get_ports { jc[3] }]; #IO_L21N_T3_DQS_A06_D22_14 Sch=jc_n[2]
#set_property -dict { PACKAGE_PIN U14   IOSTANDARD LVCMOS33 } [get_ports { jc[4] }]; #IO_L22P_T3_A05_D21_14 Sch=jc_p[3]
#set_property -dict { PACKAGE_PIN V14   IOSTANDARD LVCMOS33 } [get_ports { jc[5] }]; #IO_L22N_T3_A04_D20_14 Sch=jc_n[3]
#set_property -dict { PACKAGE_PIN T13   IOSTANDARD LVCMOS33 } [get_ports { jc[6] }]; #IO_L23P_T3_A03_D19_14 Sch=jc_p[4]
#set_property -dict { PACKAGE_PIN U13   IOSTANDARD LVCMOS33 } [get_ports { jc[7] }]; #IO_L23N_T3_A02_D18_14 Sch=jc_n[4]

##Pmod Header JD

#set_property -dict { PACKAGE_PIN D4    IOSTANDARD LVCMOS33 } [get_ports { jd[0] }]; #IO_L11N_T1_SRCC_35 Sch=jd[1]
#set_property -dict { PACKAGE_PIN D3    IOSTANDARD LVCMOS33 } [get_ports { jd[1] }]; #IO_L12N_T1_MRCC_35 Sch=jd[2]
#set_property -dict { PACKAGE_PIN F4    IOSTANDARD LVCMOS33 } [get_ports { jd[2] }]; #IO_L13P_T2_MRCC_35 Sch=jd[3]
#set_property -dict { PACKAGE_PIN F3    IOSTANDARD LVCMOS33 } [get_ports { jd[3] }]; #IO_L13N_T2_MRCC_35 Sch=jd[4]
#set_property -dict { PACKAGE_PIN E2    IOSTANDARD LVCMOS33 } [get_ports { jd[4] }]; #IO_L14P_T2_SRCC_35 Sch=jd[7]
#set_property -dict { PACKAGE_PIN D2    IOSTANDARD LVCMOS33 } [get_ports { jd[5] }]; #IO_L14N_T2_SRCC_35 Sch=jd[8]
#set_property -dict { PACKAGE_PIN H2    IOSTANDARD LVCMOS33 } [get_ports { jd[6] }]; #IO_L15P_T2_DQS_35 Sch=jd[9]
#set_property -dict { PACKAGE_PIN G2    IOSTANDARD LVCMOS33 } [get_ports { jd[7] }]; #IO_L15N_T2_DQS_35 Sch=jd[10]

##USB-UART Interface

#set_property -dict { PACKAGE_PIN D10   IOSTANDARD LVCMOS33 } [get_ports { uart_rxd_out }]; #IO_L19N_T3_VREF_16 Sch=uart_rxd_out
#set_property -dict { PACKAGE_PIN A9    IOSTANDARD LVCMOS33 } [get_ports { uart_txd_in }]; #IO_L14N_T2_SRCC_16 Sch=uart_txd_in

##ChipKit Single Ended Analog Inputs
##NOTE: The ck_an_p pins can be used as single ended analog inputs with voltages from 0-3.3V (Chipkit Analog pins A0-A5).
##      These signals should only be connected to the XADC core. When using these pins as digital I/O, use pins ck_io[14-19].

#set_property -dict { PACKAGE_PIN C5    IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[0] }]; #IO_L1N_T0_AD4N_35 Sch=ck_an_n[0]
#set_property -dict { PACKAGE_PIN C6    IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[0] }]; #IO_L1P_T0_AD4P_35 Sch=ck_an_p[0]
#set_property -dict { PACKAGE_PIN A5    IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[1] }]; #IO_L3N_T0_DQS_AD5N_35 Sch=ck_an_n[1]
#set_property -dict { PACKAGE_PIN A6    IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[1] }]; #IO_L3P_T0_DQS_AD5P_35 Sch=ck_an_p[1]
#set_property -dict { PACKAGE_PIN B4    IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[2] }]; #IO_L7N_T1_AD6N_35 Sch=ck_an_n[2]
#set_property -dict { PACKAGE_PIN C4    IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[2] }]; #IO_L7P_T1_AD6P_35 Sch=ck_an_p[2]
#set_property -dict { PACKAGE_PIN A1    IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[3] }]; #IO_L9N_T1_DQS_AD7N_35 Sch=ck_an_n[3]
#set_property -dict { PACKAGE_PIN B1    IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[3] }]; #IO_L9P_T1_DQS_AD7P_35 Sch=ck_an_p[3]
#set_property -dict { PACKAGE_PIN B2    IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[4] }]; #IO_L10N_T1_AD15N_35 Sch=ck_an_n[4]
#set_property -dict { PACKAGE_PIN B3    IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[4] }]; #IO_L10P_T1_AD15P_35 Sch=ck_an_p[4]
#set_property -dict { PACKAGE_PIN C14   IOSTANDARD LVCMOS33 } [get_ports { ck_an_n[5] }]; #IO_L1N_T0_AD0N_15 Sch=ck_an_n[5]
#set_property -dict { PACKAGE_PIN D14   IOSTANDARD LVCMOS33 } [get_ports { ck_an_p[5] }]; #IO_L1P_T0_AD0P_15 Sch=ck_an_p[5]

##ChipKit Digital I/O Low

set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports sclk]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets sclk_IBUF]

set_property -dict {PACKAGE_PIN U16 IOSTANDARD LVCMOS33} [get_ports miso]
set_property -dict {PACKAGE_PIN P14 IOSTANDARD LVCMOS33} [get_ports mosi]
set_property -dict {PACKAGE_PIN T11 IOSTANDARD LVCMOS33} [get_ports cs]
#set_property -dict {PACKAGE_PIN R12 IOSTANDARD LVCMOS33} [get_ports reset]
#set_property -dict { PACKAGE_PIN T14   IOSTANDARD LVCMOS33 } [get_ports { ck_io[5] }]; #IO_L14P_T2_SRCC_14 Sch=ck_io[5]
#set_property -dict { PACKAGE_PIN T15   IOSTANDARD LVCMOS33 } [get_ports { ck_io[6] }]; #IO_L14N_T2_SRCC_14 Sch=ck_io[6]
#set_property -dict { PACKAGE_PIN T16   IOSTANDARD LVCMOS33 } [get_ports { ck_io[7] }]; #IO_L15N_T2_DQS_DOUT_CSO_B_14 Sch=ck_io[7]
#set_property -dict { PACKAGE_PIN N15   IOSTANDARD LVCMOS33 } [get_ports { ck_io[8] }]; #IO_L11P_T1_SRCC_14 Sch=ck_io[8]
#set_property -dict { PACKAGE_PIN M16   IOSTANDARD LVCMOS33 } [get_ports { ck_io[9] }]; #IO_L10P_T1_D14_14 Sch=ck_io[9]
#set_property -dict { PACKAGE_PIN V17   IOSTANDARD LVCMOS33 } [get_ports { ck_io[10] }]; #IO_L18N_T2_A11_D27_14 Sch=ck_io[10]
#set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { ck_io[11] }]; #IO_L17N_T2_A13_D29_14 Sch=ck_io[11]
#set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { ck_io[12] }]; #IO_L12N_T1_MRCC_14 Sch=ck_io[12]
#set_property -dict { PACKAGE_PIN P17   IOSTANDARD LVCMOS33 } [get_ports { ck_io[13] }]; #IO_L12P_T1_MRCC_14 Sch=ck_io[13]

##ChipKit Digital I/O On Outer Analog Header
##NOTE: These pins should be used when using the analog header signals A0-A5 as digital I/O (Chipkit digital pins 14-19)

#set_property -dict { PACKAGE_PIN F5    IOSTANDARD LVCMOS33 } [get_ports { ck_io[14] }]; #IO_0_35 Sch=ck_a[0]
#set_property -dict { PACKAGE_PIN D8    IOSTANDARD LVCMOS33 } [get_ports { ck_io[15] }]; #IO_L4P_T0_35 Sch=ck_a[1]
#set_property -dict { PACKAGE_PIN C7    IOSTANDARD LVCMOS33 } [get_ports { ck_io[16] }]; #IO_L4N_T0_35 Sch=ck_a[2]
#set_property -dict { PACKAGE_PIN E7    IOSTANDARD LVCMOS33 } [get_ports { ck_io[17] }]; #IO_L6P_T0_35 Sch=ck_a[3]
#set_property -dict { PACKAGE_PIN D7    IOSTANDARD LVCMOS33 } [get_ports { ck_io[18] }]; #IO_L6N_T0_VREF_35 Sch=ck_a[4]
#set_property -dict { PACKAGE_PIN D5    IOSTANDARD LVCMOS33 } [get_ports { ck_io[19] }]; #IO_L11P_T1_SRCC_35 Sch=ck_a[5]

##ChipKit Digital I/O On Inner Analog Header
##NOTE: These pins will need to be connected to the XADC core when used as differential analog inputs (Chipkit analog pins A6-A11)

#set_property -dict { PACKAGE_PIN B7    IOSTANDARD LVCMOS33 } [get_ports { ck_io[20] }]; #IO_L2P_T0_AD12P_35 Sch=ad_p[12]
#set_property -dict { PACKAGE_PIN B6    IOSTANDARD LVCMOS33 } [get_ports { ck_io[21] }]; #IO_L2N_T0_AD12N_35 Sch=ad_n[12]
#set_property -dict { PACKAGE_PIN E6    IOSTANDARD LVCMOS33 } [get_ports { ck_io[22] }]; #IO_L5P_T0_AD13P_35 Sch=ad_p[13]
#set_property -dict { PACKAGE_PIN E5    IOSTANDARD LVCMOS33 } [get_ports { ck_io[23] }]; #IO_L5N_T0_AD13N_35 Sch=ad_n[13]
#set_property -dict { PACKAGE_PIN A4    IOSTANDARD LVCMOS33 } [get_ports { ck_io[24] }]; #IO_L8P_T1_AD14P_35 Sch=ad_p[14]
#set_property -dict { PACKAGE_PIN A3    IOSTANDARD LVCMOS33 } [get_ports { ck_io[25] }]; #IO_L8N_T1_AD14N_35 Sch=ad_n[14]

##ChipKit Digital I/O High

#set_property -dict { PACKAGE_PIN U11   IOSTANDARD LVCMOS33 } [get_ports { ck_io[26] }]; #IO_L19N_T3_A09_D25_VREF_14 Sch=ck_io[26]
#set_property -dict { PACKAGE_PIN V16   IOSTANDARD LVCMOS33 } [get_ports { ck_io[27] }]; #IO_L16N_T2_A15_D31_14 Sch=ck_io[27]
#set_property -dict { PACKAGE_PIN M13   IOSTANDARD LVCMOS33 } [get_ports { ck_io[28] }]; #IO_L6N_T0_D08_VREF_14 Sch=ck_io[28]
#set_property -dict { PACKAGE_PIN R10   IOSTANDARD LVCMOS33 } [get_ports { ck_io[29] }]; #IO_25_14 Sch=ck_io[29]
#set_property -dict { PACKAGE_PIN R11   IOSTANDARD LVCMOS33 } [get_ports { ck_io[30] }]; #IO_0_14 Sch=ck_io[30]
#set_property -dict { PACKAGE_PIN R13   IOSTANDARD LVCMOS33 } [get_ports { ck_io[31] }]; #IO_L5N_T0_D07_14 Sch=ck_io[31]
#set_property -dict { PACKAGE_PIN R15   IOSTANDARD LVCMOS33 } [get_ports { ck_io[32] }]; #IO_L13N_T2_MRCC_14 Sch=ck_io[32]
#set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { ck_io[33] }]; #IO_L13P_T2_MRCC_14 Sch=ck_io[33]
#set_property -dict { PACKAGE_PIN R16   IOSTANDARD LVCMOS33 } [get_ports { ck_io[34] }]; #IO_L15P_T2_DQS_RDWR_B_14 Sch=ck_io[34]
#set_property -dict { PACKAGE_PIN N16   IOSTANDARD LVCMOS33 } [get_ports { ck_io[35] }]; #IO_L11N_T1_SRCC_14 Sch=ck_io[35]
#set_property -dict { PACKAGE_PIN N14   IOSTANDARD LVCMOS33 } [get_ports { ck_io[36] }]; #IO_L8P_T1_D11_14 Sch=ck_io[36]
#set_property -dict { PACKAGE_PIN U17   IOSTANDARD LVCMOS33 } [get_ports { ck_io[37] }]; #IO_L17P_T2_A14_D30_14 Sch=ck_io[37]
#set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { ck_io[38] }]; #IO_L7N_T1_D10_14 Sch=ck_io[38]
#set_property -dict { PACKAGE_PIN R18   IOSTANDARD LVCMOS33 } [get_ports { ck_io[39] }]; #IO_L7P_T1_D09_14 Sch=ck_io[39]
#set_property -dict { PACKAGE_PIN P18   IOSTANDARD LVCMOS33 } [get_ports { ck_io[40] }]; #IO_L9N_T1_DQS_D13_14 Sch=ck_io[40]
#set_property -dict { PACKAGE_PIN N17   IOSTANDARD LVCMOS33 } [get_ports { ck_io[41] }]; #IO_L9P_T1_DQS_14 Sch=ck_io[41]

## ChipKit SPI

#set_property -dict { PACKAGE_PIN G1    IOSTANDARD LVCMOS33 } [get_ports { ck_miso }]; #IO_L17N_T2_35 Sch=ck_miso
#set_property -dict { PACKAGE_PIN H1    IOSTANDARD LVCMOS33 } [get_ports { ck_mosi }]; #IO_L17P_T2_35 Sch=ck_mosi
#set_property -dict { PACKAGE_PIN F1    IOSTANDARD LVCMOS33 } [get_ports { ck_sck }]; #IO_L18P_T2_35 Sch=ck_sck
#set_property -dict { PACKAGE_PIN C1    IOSTANDARD LVCMOS33 } [get_ports { ck_ss }]; #IO_L16N_T2_35 Sch=ck_ss

## ChipKit I2C

#set_property -dict { PACKAGE_PIN L18   IOSTANDARD LVCMOS33 } [get_ports { ck_scl }]; #IO_L4P_T0_D04_14 Sch=ck_scl
#set_property -dict { PACKAGE_PIN M18   IOSTANDARD LVCMOS33 } [get_ports { ck_sda }]; #IO_L4N_T0_D05_14 Sch=ck_sda
#set_property -dict { PACKAGE_PIN A14   IOSTANDARD LVCMOS33 } [get_ports { scl_pup }]; #IO_L9N_T1_DQS_AD3N_15 Sch=scl_pup
#set_property -dict { PACKAGE_PIN A13   IOSTANDARD LVCMOS33 } [get_ports { sda_pup }]; #IO_L9P_T1_DQS_AD3P_15 Sch=sda_pup

##Misc. ChipKit signals

#set_property -dict { PACKAGE_PIN M17   IOSTANDARD LVCMOS33 } [get_ports { ck_ioa }]; #IO_L10N_T1_D15_14 Sch=ck_ioa
#set_property -dict { PACKAGE_PIN C2    IOSTANDARD LVCMOS33 } [get_ports { ck_rst }]; #IO_L16P_T2_35 Sch=ck_rst

##SMSC Ethernet PHY

#set_property -dict { PACKAGE_PIN D17   IOSTANDARD LVCMOS33 } [get_ports { eth_col }]; #IO_L16N_T2_A27_15 Sch=eth_col
#set_property -dict { PACKAGE_PIN G14   IOSTANDARD LVCMOS33 } [get_ports { eth_crs }]; #IO_L15N_T2_DQS_ADV_B_15 Sch=eth_crs
#set_property -dict { PACKAGE_PIN F16   IOSTANDARD LVCMOS33 } [get_ports { eth_mdc }]; #IO_L14N_T2_SRCC_15 Sch=eth_mdc
#set_property -dict { PACKAGE_PIN K13   IOSTANDARD LVCMOS33 } [get_ports { eth_mdio }]; #IO_L17P_T2_A26_15 Sch=eth_mdio
#set_property -dict { PACKAGE_PIN G18   IOSTANDARD LVCMOS33 } [get_ports { eth_ref_clk }]; #IO_L22P_T3_A17_15 Sch=eth_ref_clk
#set_property -dict { PACKAGE_PIN C16   IOSTANDARD LVCMOS33 } [get_ports { eth_rstn }]; #IO_L20P_T3_A20_15 Sch=eth_rstn
#set_property -dict { PACKAGE_PIN F15   IOSTANDARD LVCMOS33 } [get_ports { eth_rx_clk }]; #IO_L14P_T2_SRCC_15 Sch=eth_rx_clk
#set_property -dict { PACKAGE_PIN G16   IOSTANDARD LVCMOS33 } [get_ports { eth_rx_dv }]; #IO_L13N_T2_MRCC_15 Sch=eth_rx_dv
#set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { eth_rxd[0] }]; #IO_L21N_T3_DQS_A18_15 Sch=eth_rxd[0]
#set_property -dict { PACKAGE_PIN E17   IOSTANDARD LVCMOS33 } [get_ports { eth_rxd[1] }]; #IO_L16P_T2_A28_15 Sch=eth_rxd[1]
#set_property -dict { PACKAGE_PIN E18   IOSTANDARD LVCMOS33 } [get_ports { eth_rxd[2] }]; #IO_L21P_T3_DQS_15 Sch=eth_rxd[2]
#set_property -dict { PACKAGE_PIN G17   IOSTANDARD LVCMOS33 } [get_ports { eth_rxd[3] }]; #IO_L18N_T2_A23_15 Sch=eth_rxd[3]
#set_property -dict { PACKAGE_PIN C17   IOSTANDARD LVCMOS33 } [get_ports { eth_rxerr }]; #IO_L20N_T3_A19_15 Sch=eth_rxerr
#set_property -dict { PACKAGE_PIN H16   IOSTANDARD LVCMOS33 } [get_ports { eth_tx_clk }]; #IO_L13P_T2_MRCC_15 Sch=eth_tx_clk
#set_property -dict { PACKAGE_PIN H15   IOSTANDARD LVCMOS33 } [get_ports { eth_tx_en }]; #IO_L19N_T3_A21_VREF_15 Sch=eth_tx_en
#set_property -dict { PACKAGE_PIN H14   IOSTANDARD LVCMOS33 } [get_ports { eth_txd[0] }]; #IO_L15P_T2_DQS_15 Sch=eth_txd[0]
#set_property -dict { PACKAGE_PIN J14   IOSTANDARD LVCMOS33 } [get_ports { eth_txd[1] }]; #IO_L19P_T3_A22_15 Sch=eth_txd[1]
#set_property -dict { PACKAGE_PIN J13   IOSTANDARD LVCMOS33 } [get_ports { eth_txd[2] }]; #IO_L17N_T2_A25_15 Sch=eth_txd[2]
#set_property -dict { PACKAGE_PIN H17   IOSTANDARD LVCMOS33 } [get_ports { eth_txd[3] }]; #IO_L18P_T2_A24_15 Sch=eth_txd[3]

##Quad SPI Flash

#set_property -dict { PACKAGE_PIN L13   IOSTANDARD LVCMOS33 } [get_ports { qspi_cs }]; #IO_L6P_T0_FCS_B_14 Sch=qspi_cs
#set_property -dict { PACKAGE_PIN K17   IOSTANDARD LVCMOS33 } [get_ports { qspi_dq[0] }]; #IO_L1P_T0_D00_MOSI_14 Sch=qspi_dq[0]
#set_property -dict { PACKAGE_PIN K18   IOSTANDARD LVCMOS33 } [get_ports { qspi_dq[1] }]; #IO_L1N_T0_D01_DIN_14 Sch=qspi_dq[1]
#set_property -dict { PACKAGE_PIN L14   IOSTANDARD LVCMOS33 } [get_ports { qspi_dq[2] }]; #IO_L2P_T0_D02_14 Sch=qspi_dq[2]
#set_property -dict { PACKAGE_PIN M14   IOSTANDARD LVCMOS33 } [get_ports { qspi_dq[3] }]; #IO_L2N_T0_D03_14 Sch=qspi_dq[3]

##Power Measurements

#set_property -dict { PACKAGE_PIN B17   IOSTANDARD LVCMOS33     } [get_ports { vsnsvu_n }]; #IO_L7N_T1_AD2N_15 Sch=ad_n[2]
#set_property -dict { PACKAGE_PIN B16   IOSTANDARD LVCMOS33     } [get_ports { vsnsvu_p }]; #IO_L7P_T1_AD2P_15 Sch=ad_p[2]
#set_property -dict { PACKAGE_PIN B12   IOSTANDARD LVCMOS33     } [get_ports { vsns5v0_n }]; #IO_L3N_T0_DQS_AD1N_15 Sch=ad_n[1]
#set_property -dict { PACKAGE_PIN C12   IOSTANDARD LVCMOS33     } [get_ports { vsns5v0_p }]; #IO_L3P_T0_DQS_AD1P_15 Sch=ad_p[1]
#set_property -dict { PACKAGE_PIN F14   IOSTANDARD LVCMOS33     } [get_ports { isns5v0_n }]; #IO_L5N_T0_AD9N_15 Sch=ad_n[9]
#set_property -dict { PACKAGE_PIN F13   IOSTANDARD LVCMOS33     } [get_ports { isns5v0_p }]; #IO_L5P_T0_AD9P_15 Sch=ad_p[9]
#set_property -dict { PACKAGE_PIN A16   IOSTANDARD LVCMOS33     } [get_ports { isns0v95_n }]; #IO_L8N_T1_AD10N_15 Sch=ad_n[10]
#set_property -dict { PACKAGE_PIN A15   IOSTANDARD LVCMOS33     } [get_ports { isns0v95_p }]; #IO_L8P_T1_AD10P_15 Sch=ad_p[10]


create_generated_clock -name slowClk -source [get_ports CLK100MHZ] -divide_by 25 [get_pins slowClk_reg/Q]
create_generated_clock -name spiClk -source [get_ports CLK100MHZ] -divide_by 2 [get_pins spiClock_reg/Q]








create_debug_core u_ila_0 ila
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 4 [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER true [get_debug_cores u_ila_0]
set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL true [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property port_width 1 [get_debug_ports u_ila_0/clk]
connect_debug_port u_ila_0/clk [get_nets [list CLK100MHZ_IBUF_BUFG]]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
set_property port_width 96 [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list {header_leftovers[0]} {header_leftovers[1]} {header_leftovers[2]} {header_leftovers[3]} {header_leftovers[4]} {header_leftovers[5]} {header_leftovers[6]} {header_leftovers[7]} {header_leftovers[8]} {header_leftovers[9]} {header_leftovers[10]} {header_leftovers[11]} {header_leftovers[12]} {header_leftovers[13]} {header_leftovers[14]} {header_leftovers[15]} {header_leftovers[16]} {header_leftovers[17]} {header_leftovers[18]} {header_leftovers[19]} {header_leftovers[20]} {header_leftovers[21]} {header_leftovers[22]} {header_leftovers[23]} {header_leftovers[24]} {header_leftovers[25]} {header_leftovers[26]} {header_leftovers[27]} {header_leftovers[28]} {header_leftovers[29]} {header_leftovers[30]} {header_leftovers[31]} {header_leftovers[32]} {header_leftovers[33]} {header_leftovers[34]} {header_leftovers[35]} {header_leftovers[36]} {header_leftovers[37]} {header_leftovers[38]} {header_leftovers[39]} {header_leftovers[40]} {header_leftovers[41]} {header_leftovers[42]} {header_leftovers[43]} {header_leftovers[44]} {header_leftovers[45]} {header_leftovers[46]} {header_leftovers[47]} {header_leftovers[48]} {header_leftovers[49]} {header_leftovers[50]} {header_leftovers[51]} {header_leftovers[52]} {header_leftovers[53]} {header_leftovers[54]} {header_leftovers[55]} {header_leftovers[56]} {header_leftovers[57]} {header_leftovers[58]} {header_leftovers[59]} {header_leftovers[60]} {header_leftovers[61]} {header_leftovers[62]} {header_leftovers[63]} {header_leftovers[64]} {header_leftovers[65]} {header_leftovers[66]} {header_leftovers[67]} {header_leftovers[68]} {header_leftovers[69]} {header_leftovers[70]} {header_leftovers[71]} {header_leftovers[72]} {header_leftovers[73]} {header_leftovers[74]} {header_leftovers[75]} {header_leftovers[76]} {header_leftovers[77]} {header_leftovers[78]} {header_leftovers[79]} {header_leftovers[80]} {header_leftovers[81]} {header_leftovers[82]} {header_leftovers[83]} {header_leftovers[84]} {header_leftovers[85]} {header_leftovers[86]} {header_leftovers[87]} {header_leftovers[88]} {header_leftovers[89]} {header_leftovers[90]} {header_leftovers[91]} {header_leftovers[92]} {header_leftovers[93]} {header_leftovers[94]} {header_leftovers[95]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
set_property port_width 256 [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list {midstate[0]} {midstate[1]} {midstate[2]} {midstate[3]} {midstate[4]} {midstate[5]} {midstate[6]} {midstate[7]} {midstate[8]} {midstate[9]} {midstate[10]} {midstate[11]} {midstate[12]} {midstate[13]} {midstate[14]} {midstate[15]} {midstate[16]} {midstate[17]} {midstate[18]} {midstate[19]} {midstate[20]} {midstate[21]} {midstate[22]} {midstate[23]} {midstate[24]} {midstate[25]} {midstate[26]} {midstate[27]} {midstate[28]} {midstate[29]} {midstate[30]} {midstate[31]} {midstate[32]} {midstate[33]} {midstate[34]} {midstate[35]} {midstate[36]} {midstate[37]} {midstate[38]} {midstate[39]} {midstate[40]} {midstate[41]} {midstate[42]} {midstate[43]} {midstate[44]} {midstate[45]} {midstate[46]} {midstate[47]} {midstate[48]} {midstate[49]} {midstate[50]} {midstate[51]} {midstate[52]} {midstate[53]} {midstate[54]} {midstate[55]} {midstate[56]} {midstate[57]} {midstate[58]} {midstate[59]} {midstate[60]} {midstate[61]} {midstate[62]} {midstate[63]} {midstate[64]} {midstate[65]} {midstate[66]} {midstate[67]} {midstate[68]} {midstate[69]} {midstate[70]} {midstate[71]} {midstate[72]} {midstate[73]} {midstate[74]} {midstate[75]} {midstate[76]} {midstate[77]} {midstate[78]} {midstate[79]} {midstate[80]} {midstate[81]} {midstate[82]} {midstate[83]} {midstate[84]} {midstate[85]} {midstate[86]} {midstate[87]} {midstate[88]} {midstate[89]} {midstate[90]} {midstate[91]} {midstate[92]} {midstate[93]} {midstate[94]} {midstate[95]} {midstate[96]} {midstate[97]} {midstate[98]} {midstate[99]} {midstate[100]} {midstate[101]} {midstate[102]} {midstate[103]} {midstate[104]} {midstate[105]} {midstate[106]} {midstate[107]} {midstate[108]} {midstate[109]} {midstate[110]} {midstate[111]} {midstate[112]} {midstate[113]} {midstate[114]} {midstate[115]} {midstate[116]} {midstate[117]} {midstate[118]} {midstate[119]} {midstate[120]} {midstate[121]} {midstate[122]} {midstate[123]} {midstate[124]} {midstate[125]} {midstate[126]} {midstate[127]} {midstate[128]} {midstate[129]} {midstate[130]} {midstate[131]} {midstate[132]} {midstate[133]} {midstate[134]} {midstate[135]} {midstate[136]} {midstate[137]} {midstate[138]} {midstate[139]} {midstate[140]} {midstate[141]} {midstate[142]} {midstate[143]} {midstate[144]} {midstate[145]} {midstate[146]} {midstate[147]} {midstate[148]} {midstate[149]} {midstate[150]} {midstate[151]} {midstate[152]} {midstate[153]} {midstate[154]} {midstate[155]} {midstate[156]} {midstate[157]} {midstate[158]} {midstate[159]} {midstate[160]} {midstate[161]} {midstate[162]} {midstate[163]} {midstate[164]} {midstate[165]} {midstate[166]} {midstate[167]} {midstate[168]} {midstate[169]} {midstate[170]} {midstate[171]} {midstate[172]} {midstate[173]} {midstate[174]} {midstate[175]} {midstate[176]} {midstate[177]} {midstate[178]} {midstate[179]} {midstate[180]} {midstate[181]} {midstate[182]} {midstate[183]} {midstate[184]} {midstate[185]} {midstate[186]} {midstate[187]} {midstate[188]} {midstate[189]} {midstate[190]} {midstate[191]} {midstate[192]} {midstate[193]} {midstate[194]} {midstate[195]} {midstate[196]} {midstate[197]} {midstate[198]} {midstate[199]} {midstate[200]} {midstate[201]} {midstate[202]} {midstate[203]} {midstate[204]} {midstate[205]} {midstate[206]} {midstate[207]} {midstate[208]} {midstate[209]} {midstate[210]} {midstate[211]} {midstate[212]} {midstate[213]} {midstate[214]} {midstate[215]} {midstate[216]} {midstate[217]} {midstate[218]} {midstate[219]} {midstate[220]} {midstate[221]} {midstate[222]} {midstate[223]} {midstate[224]} {midstate[225]} {midstate[226]} {midstate[227]} {midstate[228]} {midstate[229]} {midstate[230]} {midstate[231]} {midstate[232]} {midstate[233]} {midstate[234]} {midstate[235]} {midstate[236]} {midstate[237]} {midstate[238]} {midstate[239]} {midstate[240]} {midstate[241]} {midstate[242]} {midstate[243]} {midstate[244]} {midstate[245]} {midstate[246]} {midstate[247]} {midstate[248]} {midstate[249]} {midstate[250]} {midstate[251]} {midstate[252]} {midstate[253]} {midstate[254]} {midstate[255]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
set_property port_width 32 [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list {nonce[0]} {nonce[1]} {nonce[2]} {nonce[3]} {nonce[4]} {nonce[5]} {nonce[6]} {nonce[7]} {nonce[8]} {nonce[9]} {nonce[10]} {nonce[11]} {nonce[12]} {nonce[13]} {nonce[14]} {nonce[15]} {nonce[16]} {nonce[17]} {nonce[18]} {nonce[19]} {nonce[20]} {nonce[21]} {nonce[22]} {nonce[23]} {nonce[24]} {nonce[25]} {nonce[26]} {nonce[27]} {nonce[28]} {nonce[29]} {nonce[30]} {nonce[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe3]
set_property port_width 3 [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list {shaState[0]} {shaState[1]} {shaState[2]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe4]
set_property port_width 256 [get_debug_ports u_ila_0/probe4]
connect_debug_port u_ila_0/probe4 [get_nets [list {target[0]} {target[1]} {target[2]} {target[3]} {target[4]} {target[5]} {target[6]} {target[7]} {target[8]} {target[9]} {target[10]} {target[11]} {target[12]} {target[13]} {target[14]} {target[15]} {target[16]} {target[17]} {target[18]} {target[19]} {target[20]} {target[21]} {target[22]} {target[23]} {target[24]} {target[25]} {target[26]} {target[27]} {target[28]} {target[29]} {target[30]} {target[31]} {target[32]} {target[33]} {target[34]} {target[35]} {target[36]} {target[37]} {target[38]} {target[39]} {target[40]} {target[41]} {target[42]} {target[43]} {target[44]} {target[45]} {target[46]} {target[47]} {target[48]} {target[49]} {target[50]} {target[51]} {target[52]} {target[53]} {target[54]} {target[55]} {target[56]} {target[57]} {target[58]} {target[59]} {target[60]} {target[61]} {target[62]} {target[63]} {target[64]} {target[65]} {target[66]} {target[67]} {target[68]} {target[69]} {target[70]} {target[71]} {target[72]} {target[73]} {target[74]} {target[75]} {target[76]} {target[77]} {target[78]} {target[79]} {target[80]} {target[81]} {target[82]} {target[83]} {target[84]} {target[85]} {target[86]} {target[87]} {target[88]} {target[89]} {target[90]} {target[91]} {target[92]} {target[93]} {target[94]} {target[95]} {target[96]} {target[97]} {target[98]} {target[99]} {target[100]} {target[101]} {target[102]} {target[103]} {target[104]} {target[105]} {target[106]} {target[107]} {target[108]} {target[109]} {target[110]} {target[111]} {target[112]} {target[113]} {target[114]} {target[115]} {target[116]} {target[117]} {target[118]} {target[119]} {target[120]} {target[121]} {target[122]} {target[123]} {target[124]} {target[125]} {target[126]} {target[127]} {target[128]} {target[129]} {target[130]} {target[131]} {target[132]} {target[133]} {target[134]} {target[135]} {target[136]} {target[137]} {target[138]} {target[139]} {target[140]} {target[141]} {target[142]} {target[143]} {target[144]} {target[145]} {target[146]} {target[147]} {target[148]} {target[149]} {target[150]} {target[151]} {target[152]} {target[153]} {target[154]} {target[155]} {target[156]} {target[157]} {target[158]} {target[159]} {target[160]} {target[161]} {target[162]} {target[163]} {target[164]} {target[165]} {target[166]} {target[167]} {target[168]} {target[169]} {target[170]} {target[171]} {target[172]} {target[173]} {target[174]} {target[175]} {target[176]} {target[177]} {target[178]} {target[179]} {target[180]} {target[181]} {target[182]} {target[183]} {target[184]} {target[185]} {target[186]} {target[187]} {target[188]} {target[189]} {target[190]} {target[191]} {target[192]} {target[193]} {target[194]} {target[195]} {target[196]} {target[197]} {target[198]} {target[199]} {target[200]} {target[201]} {target[202]} {target[203]} {target[204]} {target[205]} {target[206]} {target[207]} {target[208]} {target[209]} {target[210]} {target[211]} {target[212]} {target[213]} {target[214]} {target[215]} {target[216]} {target[217]} {target[218]} {target[219]} {target[220]} {target[221]} {target[222]} {target[223]} {target[224]} {target[225]} {target[226]} {target[227]} {target[228]} {target[229]} {target[230]} {target[231]} {target[232]} {target[233]} {target[234]} {target[235]} {target[236]} {target[237]} {target[238]} {target[239]} {target[240]} {target[241]} {target[242]} {target[243]} {target[244]} {target[245]} {target[246]} {target[247]} {target[248]} {target[249]} {target[250]} {target[251]} {target[252]} {target[253]} {target[254]} {target[255]}]]


set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets CLK100MHZ_IBUF_BUFG]
