import numpy as np
from scipy.stats import norm

def black_scholes_call(S, K, T, r, sigma, q):
    d1 = (np.log(S / K) + (r - q + 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    d2 = d1 - sigma * np.sqrt(T)
    
    call_price = (S * np.exp(-q * T) * norm.cdf(d1)) - (K * np.exp(-r * T) * norm.cdf(d2))
    return call_price

# Stock 1: ABC Corporation
S1 = 150    # Current stock price
K1 = 155    # Strike price
T1 = 0.5    # Time to expiration (6 months)
r1 = 0.03   # Risk-free interest rate (3%)
sigma1 = 0.25  # Volatility (25%)
q1 = 0.02   # Dividend yield (2%)

# Stock 2: XYZ Inc.
S2 = 200    # Current stock price
K2 = 210    # Strike price
T2 = 1      # Time to expiration (1 year)
r2 = 0.04   # Risk-free interest rate (4%)
sigma2 = 0.30  # Volatility (30%)
q2 = 0.01   # Dividend yield (1%)

call_price1 = black_scholes_call(S1, K1, T1, r1, sigma1, q1)
call_price2 = black_scholes_call(S2, K2, T2, r2, sigma2, q2)

print("Call Price for ABC Corporation: {:.2f}".format(call_price1))
print("Call Price for XYZ Inc.: {:.2f}".format(call_price2))

