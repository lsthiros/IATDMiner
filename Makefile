all: test_bs

test_bs: block_solver_test.sv block_solver.sv message_schedule.v sha_core.v sha_round.v  k_table.v
	iverilog -g2012 -o block_solver_test block_solver_test.sv block_solver.sv message_schedule.v sha_core.v sha_round.v  k_table.v
