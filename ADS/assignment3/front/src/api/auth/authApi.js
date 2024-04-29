import axios from "axios";
const baseURL = "http://localhost:3001/api";

const authApi = axios.create({ baseURL });
export const loginUser = async (email, password) => {
  try {
    const response = await authApi.post("/login", { email, password });
    return response.data;
  } catch (error) {
    throw error;
  }
};

export const registerUser = async (username, email, password, role) => {
  try {
    const response = await authApi.post("/signup", {
      username,
      email,
      password,
      role,
    });
    return response.data;
  } catch (error) {
    throw error;
  }
};
