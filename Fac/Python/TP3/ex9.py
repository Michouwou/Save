v1 = 1
i = 0

while (v1 < 10):
	v2 = 1
	while (v2 < 10):
		v3 = 1
		if (v2 != v1):
			while (v3 < 10):
				v4 = 1
				if (v3 != v2 and v3 != v1):
					while (v4 < 10):
						v5 = 1
						if (v4 != v3 and v4 != v2 and v4 != v1):
							while (v5 < 10):
								v6 = 1
								if (v5 != v4 and v5 != v3 and v5 != v2 and v5 != v1):
									while (v6 < 10):
										v7 = 1
										if (v6 != v5 and v6 != v4 and v6 != v3 and v6 != v2 and v6 != v1):
											while (v7 < 10):
												v8 = 1
												if (v7 != v6 and v7 != v5 and v7 != v4 and v7 != v3 and v7 != v2 and v7 != v1):
													while (v8 < 10):
														v9 = 1
														if (v8 != v7 and v8 != v6 and v8 != v5 and v8 != v4 and v8 != v3 and v8 != v2 and v8 != v1):
															while (v9 < 10):
																if (v9 != v8 and v9 != v7 and v9 != v6 and v9 != v5 and v9 != v4 and v9 != v3 and v9 != v2 and v9 != v1):
																	if (v1 + 13 * v2 / v3 + v4 + 12 * v5 - v6 - 11 + v7 * v8 / v9 - 10 == 66):
																		print("Solutions : ", v1, v2, v3, v4, v5, v6, v7, v8, v9)
																		i += 1
																v9 += 1
														v8 += 1
												v7 += 1
										v6 += 1
								v5 += 1
						v4 += 1
				v3 += 1
		v2 += 1
	v1 += 1

print(i, "solutions trouvees")
