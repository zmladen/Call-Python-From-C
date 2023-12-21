# utulity.py

import torch

def calculate_mean(numbers):
    # Convert the list to a tensor of floating point type
    tensor = torch.tensor(numbers, dtype=torch.float)
    return torch.mean(tensor).item()

def get_torch_version():
    return str(torch.__version__)