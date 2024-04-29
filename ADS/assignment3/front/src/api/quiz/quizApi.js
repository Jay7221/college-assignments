import axios from "axios";

const baseURL = "http://localhost:3001/api";
const quizApi = axios.create({
  baseURL,
});

quizApi.interceptors.request.use(
  (config) => {
    const token = localStorage.getItem("token");
    if (token) {
      config.headers.Authorization = token;
    }
    return config;
  },
  (error) => {
    return Promise.reject(error);
  }
);

export const fetchQuizList = async () => {
  try {
    const response = await quizApi.get("/quizzes");
    return response.data;
  } catch (error) {
    console.log(error);
    throw error;
  }
};

export const createQuiz = async (quizData) => {
  try {
    const response = await quizApi.post("/quizzes", quizData);
    return response.data;
  } catch (error) {
    throw error;
  }
};
export const addQuestionToQuiz = async (quizId, questionData) => {
  try {
    console.log(questionData);
    const response = await quizApi.post(
      `/quizzes/${quizId}/questions`,
      questionData
    );
    return response.data;
  } catch (error) {
    throw error;
  }
};

export const fetchQuestionsForQuiz = async (quizId) => {
  try {
    const response = await quizApi.get(`/quizzes/${quizId}/questions`);
    return response.data;
  } catch (error) {
    throw error;
  }
};

export const submitQuiz = async (quizId, answers) => {
  try {
    const response = await quizApi.post(`/quizzes/${quizId}/submit`, {
      answers,
    });
    return response.data;
  } catch (error) {
    throw error;
  }
};

export const fetchSubmission = async (submissionId) => {
  try {
    const response = await quizApi.get(`/submission/${submissionId}`);
    return response.data;
  } catch (error) {
    throw error;
  }
};
