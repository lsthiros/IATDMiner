all: test_bs test_sha

test_bs: block_solver_test.sv block_solver.sv message_schedule.v sha_core.v sha_round.v  k_table.v
	iverilog -g2012 -o block_solver_test block_solver_test.sv block_solver.sv message_schedule.v sha_core.v sha_round.v  k_table.v

test_sha: sha_core_test sha_core.v sha_core_test.v message_schedule.v sha_round.v  k_table.v
	iverilog -g2012 -o sha_core_test sha_core.v sha_core_test.v message_schedule.v sha_round.v  k_table.v
